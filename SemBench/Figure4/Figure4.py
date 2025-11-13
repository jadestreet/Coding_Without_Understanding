import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from matplotlib.gridspec import GridSpec
from matplotlib import patheffects as pe
from matplotlib.ticker import AutoMinorLocator
from io import StringIO
import os
import re

# -------------------------
# Global style
# -------------------------
plt.rcParams.update({
    "font.size": 12,        # slightly smaller to fit 12 panels
    "axes.titlesize": 13,
    "axes.labelsize": 12,
    "xtick.labelsize": 11,
    "ytick.labelsize": 11,
    "legend.fontsize": 9,
    "axes.linewidth": 1.1,
    "xtick.direction": "out",
    "ytick.direction": "out",
    "xtick.major.size": 4.5,
    "ytick.major.size": 4.5,
    "xtick.minor.size": 2.5,
    "ytick.minor.size": 2.5,
    "grid.linewidth": 0.6,
})

# -------------------------
# Data (inline CSV from user)
# -------------------------
csv_text = """model,family,All_byquestionscount_p1,HumanEval_p1,MBPP_p1,DataDep_p1,DeadCode_p1,Dominators_p1,FuncReach_p1,Liveness_p1,LoopReach_p1,All_averagecategory_p1,All_geo_p1
GPT-5-Codex,GPT,78.94,,,89.28,89.05,97,97.83,33.96,64.96,78.68,74.17
GPT-5,GPT,72.68,93.4,,79.86,91.15,96.48,76.44,32.26,64.53,73.45,69.40
GPT-4o Mini,GPT,70.21,88.4,,82.97,86.4,100,58.85,36.79,67.56,72.10,68.67
GPT-3.5 Turbo,GPT,70.55,71.9,,66.13,58.27,95.22,69.05,37.71,84.5,68.48,65.74
DeepSeek-Coder V2-Lite-Instr,DeepSeek,65.55,81.1,68.8,78.81,57.4,47.63,77.79,50.99,68.17,63.47,62.26
DeepSeek-Coder 7B-Instr v1.5,DeepSeek,44.79,64.1,64.6,41.98,51.05,45.14,41.18,36.23,50.41,44.33,44.02
DeepSeek-R1-Distill-Qwen-7B,DeepSeek,18.11,,17.2,34.87,15.9,4.27,14.4,22.14,18.98,18.43,15.58
CodeLlama-13B-Instr,Llama,41.93,42.7,49.4,46.69,50.9,31.5,45.38,39.64,38.19,42.05,41.55
CodeLlama-7B-Instr,Llama,50.41,34.8,44.4,80.31,49.35,12.06,52.31,62.19,47.35,50.60,44.11
Llama-3 8B-Instr,Llama,41.6,72.6,,37.42,63.4,23.51,48.56,35.47,38.45,41.14,39.32
Mistral 7B-Instr (v0.3),Mistral,64.44,,,67.79,60.6,59.69,70.12,52.21,68.07,63.08,62.76
Mamba Codestral 7B (v0.1),Mistral,39.98,75,68.5,37.02,30.85,38.98,54.82,33.38,36.54,38.60,37.93
Qwen2.5-Coder 14B-Instr,Qwen,54.13,89.6,86.2,50.65,89.95,73.33,49.38,25.34,46.77,55.90,51.90
Qwen3 14B,Qwen,40.02,,73.4,27.61,61,48.5,58.4,19.85,24.89,40.04,36.48
StarCoder 2 7B,StarCoder,36.74,30.5,47.4,39.98,61.85,17.2,36.08,37.15,32.49,37.46,35.04
Phi-4 Reasoning (14B),Phi,22.6,,12.5,21.24,51.55,8.6,23.73,14.76,18.45,23.06,19.83
"""

df = pd.read_csv(StringIO(csv_text))

# -------------------------
# Unique markers per model
# -------------------------
# A stable list of distinct markers; repeat if more models than markers
marker_cycle = ["o", "s", "D", "^", "v", "<", ">", "P", "X", "*", "H", "+", "x", "1", "2", "3", "4"]
markers = {model: marker_cycle[i % len(marker_cycle)] for i, model in enumerate(df["model"].tolist())}
df["Marker"] = df["model"].map(markers)
# -------------------------
# Consistent color mapping for models
# -------------------------
color_cycle = plt.rcParams["axes.prop_cycle"].by_key()["color"]
color_map = {model: color_cycle[i % len(color_cycle)] for i, model in enumerate(df["model"])}



# -------------------------
# Helper: add linear fit + ρ text with white halo
# -------------------------
def add_fit_line(ax, x_series, y_series, line_kwargs=None, text_anchor=(0.03, 0.97)):
    if line_kwargs is None:
        line_kwargs = {"linewidth": 2, "alpha": 0.9}

    x = np.asarray(x_series, dtype=float)
    y = np.asarray(y_series, dtype=float)
    mask = ~np.isnan(x) & ~np.isnan(y)
    x = x[mask]; y = y[mask]
    if x.size < 2:
        return

    m, b = np.polyfit(x, y, deg=1)
    xs = np.linspace(0, 100, 200)
    ys = m * xs + b

    line = ax.plot(xs, ys, zorder=3, solid_capstyle="round", **line_kwargs)[0]
    line.set_path_effects([pe.Stroke(linewidth=line.get_linewidth() + 2.0, foreground="white"),
                           pe.Normal()])

    # Spearman rho
    try:
        from scipy.stats import spearmanr
        rho, pval = spearmanr(x, y)

        # significance stars
        if pval <= 0.001:
            stars = "***"
        elif pval <= 0.01:
            stars = "**"
        elif pval <= 0.05:
            stars = "*"
        else:
            stars = ""

        sp_text = (
            rf"$\rho = {rho:.2f}$(p-value={pval:.3f}{stars})")
        

    except Exception:
        xr = pd.Series(x).rank().to_numpy()
        yr = pd.Series(y).rank().to_numpy()
        rho = np.corrcoef(xr, yr)[0, 1]
        sp_text = rf"$\rho = {rho:.2f}$"
    # Annotate (equation + rho)
    sign = "+" if b >= 0 else "−"
    eq_text = rf"$y = {m:.2f}x\, {sign}\, {abs(b):.2f}$"
    txt = ax.text(
        text_anchor[0], text_anchor[1],
        eq_text + "\n" + sp_text,
        transform=ax.transAxes,
        va=("top" if text_anchor[1] > 0.5 else "bottom"),
        ha=("left" if text_anchor[0] < 0.5 else "right"),
        fontsize=9, #fontweight="semibold",
        bbox=dict(boxstyle="round,pad=0.25,rounding_size=0.15", fc="white", ec="#D0D0D0", alpha=0.9),
        zorder=4
    )
    txt.set_path_effects([pe.Stroke(linewidth=1.2, foreground="white"), pe.Normal()])

# -------------------------
# Figure layout: 2 rows x 6 columns
# -------------------------
# Columns correspond to the 6 semantic categories
cat_cols = [
    ("Data Dependency", "DataDep_p1"),
    ("Dead Code", "DeadCode_p1"),
    ("Dominators", "Dominators_p1"),
    ("Function Reachability", "FuncReach_p1"),
    ("Liveness", "Liveness_p1"),
    ("Loop Reachability", "LoopReach_p1"),
]

fig = plt.figure(figsize=(18, 6.8))  # wide but compact; OK for Nature full-width
gs = GridSpec(2, 6, wspace=0.25, hspace=0.35)

axes = []
for r in range(2):
    row_axes = []
    for c in range(6):
        row_axes.append(fig.add_subplot(gs[r, c]))
    axes.append(row_axes)

# Styling helper
def style_ax(ax, title=None, xlabel=None, ylabel=None):
    # spines
    ax.spines["left"].set_color("#3A3A3A");   ax.spines["left"].set_linewidth(1.1)
    ax.spines["bottom"].set_color("#3A3A3A"); ax.spines["bottom"].set_linewidth(1.1)
    ax.spines["top"].set_color("#BDBDBD");    ax.spines["top"].set_linewidth(0.9)
    ax.spines["right"].set_color("#BDBDBD");  ax.spines["right"].set_linewidth(0.9)
    # grid
    ax.xaxis.set_minor_locator(AutoMinorLocator(2))
    ax.yaxis.set_minor_locator(AutoMinorLocator(2))
    ax.grid(which="major", linestyle="--", color="#B0B0B0", alpha=0.35)
    ax.grid(which="minor", linestyle=":",  color="#CFCFCF", alpha=0.25)
    ax.set_axisbelow(True)
    if title:  ax.set_title(title)
    if xlabel: ax.set_xlabel(xlabel)
    if ylabel: ax.set_ylabel(ylabel)
    # lock display ranges to 0-100 for apples-to-apples across panels
    ax.set_xlim(0, 100)
    ax.set_ylim(0, 100)

# -------------------------
# Plotting
# -------------------------
# Top row: HumanEval vs category
for j, (nice_name, col) in enumerate(cat_cols):
    ax = axes[0][j]
    style_ax(ax, title=nice_name, xlabel="HumanEval Pass@1 (%)", ylabel=("Accuracy (%)" if j == 0 else None))
    sub = df.dropna(subset=["HumanEval_p1", col])
    for _, row in sub.iterrows():
        ax.scatter(
            row["HumanEval_p1"], row[col],
            marker=row["Marker"], s=70,
            color=color_map[row["model"]],
            zorder=5
        )
    add_fit_line(ax, sub["HumanEval_p1"].values if len(sub) else np.array([]),
                    sub[col].values if len(sub) else np.array([]),
                 line_kwargs={"linewidth": 2, "alpha": 0.9}, text_anchor=(0.03, 0.97))

# Bottom row: MBPP vs category
for j, (nice_name, col) in enumerate(cat_cols):
    ax = axes[1][j]
    style_ax(ax, title=None, xlabel="MBPP Pass@1 (%)", ylabel=("Accuracy (%)" if j == 0 else None))
    sub = df.dropna(subset=["MBPP_p1", col])
    for _, row in sub.iterrows():
        ax.scatter(
            row["MBPP_p1"], row[col],
            marker=row["Marker"], s=70,
            color=color_map[row["model"]],
            zorder=5
        )

    add_fit_line(ax, sub["MBPP_p1"].values if len(sub) else np.array([]),
                    sub[col].values if len(sub) else np.array([]),
                 line_kwargs={"linewidth": 2, "alpha": 0.9, "linestyle": "--"},
                 text_anchor=(0.03, 0.97))


# -------------------------
# Figure-level legend (colors consistent with figure)
# -------------------------
handles, labels = [], []
for _, row in df.iterrows():
    h = plt.Line2D(
        [], [], 
        marker=row["Marker"], linestyle="None",
        markersize=8,
        color=color_map[row["model"]],   # <---- same color as scatter
        label=row["model"]
    )
    handles.append(h)
    labels.append(row["model"])

fig.legend(
    handles, labels,
    loc="upper center", ncol=5, frameon=False,
    bbox_to_anchor=(0.5, -0.02), fontsize=9
)

plt.tight_layout(rect=[0, 0.15, 1, 1])  # leave room for legend

# -------------------------
# Save
# -------------------------
out_dir = os.getcwd()
pdf_path = os.path.join(out_dir, "Figure 3_sub.pdf")
png_path = os.path.join(out_dir, "Figure 3_sub.png")
plt.savefig(pdf_path, format="pdf", bbox_inches="tight")
plt.savefig(png_path, format="png", dpi=300, bbox_inches="tight")
plt.close()

print(f"Saved:\n  {pdf_path}\n  {png_path}")
