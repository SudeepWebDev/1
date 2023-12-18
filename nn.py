from sympy import symbols, diff, Matrix

# Define variables
x1, x2 = symbols('x1 x2')

# Define the function
f = 100 * (x2 - x1**2)**2 + (1 - x1)**2

# Compute the gradient
grad_f = [diff(f, x1), diff(f, x2)]

# Compute the Hessian
hessian_f = [[diff(diff(f, x1_i), x2_j) for x1_i in [x1, x2]] for x2_j in [x1, x2]]

# Print results
print("Gradient of f:", grad_f)
print("Hessian of f:")
print(Matrix(hessian_f))
