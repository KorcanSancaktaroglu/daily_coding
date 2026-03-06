import time

class RootHunter:
    def __init__(self, function):
        self.f = function
        self.history = []

    def bisection(self, a, b, tol=1e-6, max_iter=50):
        start_cpu = time.perf_counter()
        f_a, f_b = self.f(a), self.f(b)
        
        if f_a * f_b >= 0:
            raise ValueError("Root not bracketed! Check signs of f(a) and f(b).")

        print(f"{'STEP':<6} | {'C-VALUE':<12} | {'PRECISION':<12}")
        print("-" * 40)

        for i in range(1, max_iter + 1):
            precision = abs(b - a) / 2
            c = a + (b - a) / 2  # Stable midpoint calculation
            f_c = self.f(c)
            
            self.history.append(precision)
            print(f"{i:<6} | {c:<12.6f} | {precision:<12.3e}")

            if abs(f_c) < tol or precision < tol:
                duration = time.perf_counter() - start_cpu
                print("-" * 40)
                print(f"Target: {c:.10f} | Time: {duration:.6f}s")
                return c

            # Update boundaries
            if f_a * f_c < 0:
                b, f_b = c, f_c
            else:
                a, f_a = c, f_c

        return c

if __name__ == "__main__":
    target_eq = lambda x: x**3 + 4*x**2 - 10
    hunter = RootHunter(target_eq)
    hunter.bisection(1, 2, tol=1e-5)
