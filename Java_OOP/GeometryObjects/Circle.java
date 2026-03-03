public class Circle {
    private double radius;
    public static int circleCount = 0;

    public Circle(double radius) {
        setRadius(radius);
        circleCount++;
    }

    public void setRadius(double radius) {
        this.radius = (radius >= 0) ? radius : 0;
    }

    public double getRadius() {
        return this.radius;
    }

    public double calculateArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }

    public double calculatePerimeter() {
        return 2 * Math.PI * this.radius;
    }
}
