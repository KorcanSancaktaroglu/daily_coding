package math;


public class Logarithm {

    
    public static double calculateLog(double base, double value) {
        if (base <= 0 || base == 1) {
            throw new IllegalArgumentException("Base must be greater than 0 and not equal to 1.");
        }
        if (value <= 0) {
            throw new IllegalArgumentException("Value must be greater than 0.");
        }

        return Math.log(value) / Math.log(base);
    }
}
