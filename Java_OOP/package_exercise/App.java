import math.BasicCalculator;
import math.Logarithm;

/**
 * Main application entry point for testing mathematical operations.
 * Part of the daily coding repository.
 */
public class App {
    public static void main(String[] args) {
        // Initialization of arithmetic operations
        BasicCalculator calculator = new BasicCalculator();
        int sum = calculator.add(1, 5);
        System.out.println("Addition Result (1 + 5): " + sum);

        // Usage of static logarithm method
        // Since calculateLog is static, we can call it directly via the class name
        double logResult = Logarithm.calculateLog(2, 8);
        System.out.println("Logarithm Result (base 2, value 8): " + logResult);
    }
}
