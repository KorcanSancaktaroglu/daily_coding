import time

def newton_raphson(f, df, x0, tol=1e-7, max_iter=100):
    """
    Newton-Raphson method for finding roots.
    Formula: x_new = x_old - f(x_old) / f'(x_old)
    """
    start_time = time.perf_counter()
    x = x0
    
    print(f"{'Step':<6} | {'x_n':<12} | {'f(x_n)':<12}")
    print("-" * 35)

    for i in range(1, max_iter + 1):
        fx = f(x)
        dfx = df(x)
        
        # Avoid division by zero
        if abs(dfx) < 1e-12:
            print("Mathematical Error: Derivative is too small.")
            return None
            
        step_size = fx / dfx
        x = x - step_size # Core update
        
        print(f"{i:<6} | {x:<12.8f} | {fx:<12.2e}")

        # Convergence check
        if abs(step_size) < tol:
            duration = time.perf_counter() - start_time
            print("-" * 35)
            print(f"Success! Root: {x:.10f} | Time: {duration:.8f}s")
            return x

    print("Max iterations reached.")
    return x

# Define target: f(x) = x^2 - 2 (finding sqrt of 2)
f = lambda x: x**2 - 2
df = lambda x: 2*x

# Execute the search
result = newton_raphson(f, df, x0=10)
