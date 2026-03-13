import time

def regula_falsi(f, a, b, tol=1e-6, max_iter=100):
    """
    Regula Falsi Method: Uses a linear chord (secant) to find the root within [a, b].
    """
    start_time = time.perf_counter()
    fa, fb = f(a), f(b)

    if fa * fb >= 0:
        print("Error: IVT condition failed. Signs at boundaries must differ.")
        return None

    print(f"{'Step':<6} | {'c (Root)':<12} | {'f(c)':<12}")
    print("-" * 40)

    for i in range(1, max_iter + 1):
        # Linear interpolation formula for the root estimate
        c = (a * fb - b * fa) / (fb - fa)
        fc = f(c)

        print(f"{i:<6} | {c:<12.7f} | {fc:<12.2e}")

        # Convergence Check
        if abs(fc) < tol:
            duration = time.perf_counter() - start_time
            print("-" * 40)
            print(f"Success! Root: {c:.10f} | Time: {duration:.8f}s")
            return c

        # Narrow down the interval
        if fa * fc < 0:
            b, fb = c, fc  # Root is on the left
        else:
            a, fa = c, fc  # Root is on the right

    print("Max iterations reached.")
    return c

# Define the target function (from your notes)
f_target = lambda x: x - (2**(-x))

# Execute the search
result = regula_falsi(f_target, 0, 1)
