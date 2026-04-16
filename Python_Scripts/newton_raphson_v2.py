import sympy as sp
import time as t

def newton_raphson():
    # User Input
    equation_str = input("Function (e.g., x**2 - 2): ")
    try:
        x_val = float(input("Initial Guess (x0): "))
    except ValueError:
        print("Invalid input!")
        return
        
    tolerance = 1e-6

    # Symbolic Math Setup
    x_sym = sp.symbols('x')
    f_expr = sp.sympify(equation_str)
    df_expr = sp.diff(f_expr, x_sym)

    # Numerical Conversion
    f = sp.lambdify(x_sym, f_expr)
    df = sp.lambdify(x_sym, df_expr)

    iteration = 0
    start_time = t.time()

    print(f"\nSolving: {f_expr} | Derivative: {df_expr}")

    try:
        while True:
            iteration += 1
            f_x = f(x_val)
            df_x = df(x_val)
            
            if df_x == 0:
                print("Error: Zero derivative.")
                return

            step = f_x / df_x
            x_val -= step
            
            if abs(step) < tolerance:
                break
        
        elapsed = t.time() - start_time
        
        print("-" * 30)
        print(f"Root: {x_val}\nIterations: {iteration}\nTime: {elapsed:.6f}s")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    newton_raphson()
