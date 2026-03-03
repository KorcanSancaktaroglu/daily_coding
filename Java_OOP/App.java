public class App {
    public static void main(String[] args) throws Exception {
        // Temperature values array
        double[] temperatures = {55.5, 11.1, 44.4, 33.3};
        
        double max, min, total = 0, average;
        max = temperatures[0];
        min = temperatures[0];
        
        int n = temperatures.length;
        int countAboveAverage = 0;

        for (int i = 0; i < n; i++) {
            total += temperatures[i];
            if (temperatures[i] > max) {
                max = temperatures[i];
            }
            if (temperatures[i] < min) {
                min = temperatures[i];
            }
        }

        IO.println("Maximum Value: " + max);
        IO.println("Minimum Value: " + min);

        average = total / n;
        IO.println("Average Value: " + average);

        for (int i = 0; i < n; i++) {
            if (temperatures[i] > average) {
                IO.println("Value above average: " + temperatures[i]);
                countAboveAverage++;
            }
        }
        IO.println("Count of values above average: " + countAboveAverage);
        
        for (int i = n - 1; i >= 0; i--) {
            IO.println("Temperature Value (Reverse): " + temperatures[i]);
        }
    }
}
