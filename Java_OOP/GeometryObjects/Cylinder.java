public class Cylinder extends Circle {
    private double height;
    public static int cylinderCount = 0;

    public Cylinder(double radius, double height) {
        super(radius);
        setHeight(height);
        cylinderCount++;
    }

    public void setHeight(double height) {
        this.height = (height >= 0) ? height : 0;
    }

    public double calculateVolume() {
        return calculateArea() * this.height;
    }
}
