# Import matplotlib.pyplot as plt
import matplotlib.pyplot as plt

# Define the objective function and the constraints
def objective(x, y):
    return 4 * x + 3 * y

def constraint1(x, y):
    return x + 2 * y - 8

def constraint2(x, y):
    return 2 * x + y - 10

# Define the range of x and y values
x = [0, 5]
y = [0, 5]

# Plot the constraint lines
plt.plot(x, [4 - 0.5 * xi for xi in x], label="x + 2y = 8")
plt.plot(x, [10 - 2 * xi for xi in x], label="2x + y = 10")

# Shade the valid side of each constraint line
plt.fill([0, 0, 5], [0, 4, 0], color="blue", alpha=0.2, label="x + 2y <= 8")
plt.fill([0, 0, 5], [0, 10, 0], color="red", alpha=0.2, label="2x + y <= 10")

# Plot the objective function line
plt.plot(x, [objective(xi, 0) / 3 for xi in x], label="z = 4x + 3y", linestyle="--")

# Find and plot the optimum point
x_opt = 2
y_opt = 3
z_opt = objective(x_opt, y_opt)
plt.scatter(x_opt, y_opt, marker="o", color="black", label=f"Optimum point ({x_opt}, {y_opt})")

# Set the axis limits and labels
plt.axis([0, 5, 0, 5])
plt.xlabel("x")
plt.ylabel("y")

# Add a legend and a title
plt.legend()
plt.title(f"Maximize z = {z_opt} at (x, y) = ({x_opt}, {y_opt})")

# Show the plot
plt.show()
