import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Radius: ");
        double r = input.nextDouble();
        Circle circle = new Circle(r);

        System.out.print("Height: ");
        double h = input.nextDouble();
        Cylinder cylinder = new Cylinder(r, h);

        System.out.println("\nResults:");
        System.out.println("Area: " + String.format("%.2f", circle.calculateArea()));
        System.out.println("Volume: " + String.format("%.2f", cylinder.calculateVolume()));

        System.out.println("\nCounts:");
        System.out.println("Circles: " + Circle.circleCount);
        System.out.println("Cylinders: " + Cylinder.cylinderCount);

        input.close();
    }
}
