import java.util.ArrayList;
import java.util.Arrays;

class Pizza {
    // ---------- Static Constants (Shared by all) ----------
    private static final ArrayList<String> VALID_SIZES = new ArrayList<>(Arrays.asList("Small", "Large"));
    private static final ArrayList<String> VALID_CRUSTS = new ArrayList<>(Arrays.asList("Thin", "Thick"));
    private static final ArrayList<String> VALID_TOPPINGS = new ArrayList<>(Arrays.asList("Mozzarella", "Salami", "Olives", "Peppers", "Mushrooms"));
    private static final int MAX_TOPPINGS = 3;

    // ---------- Fields ----------
    private static int totalOrders = 0; // Static: Tracks overall count
    private final int orderNo;          // Final: Set once, never changed
    private String size;
    private String crustType;
    private ArrayList<String> toppings;

    // ---------- Constructors ----------
    
    // Full Constructor
    public Pizza(String size, String crustType, ArrayList<String> toppings) {
        totalOrders++;
        this.orderNo = totalOrders;
        this.toppings = new ArrayList<>(); // Initialize empty list first
        
        setSize(size);
        setCrustType(crustType);
        
        // Add toppings one by one to trigger validation
        if (toppings != null) {
            for (String t : toppings) {
                addTopping(t);
            }
        }
    }

    // Overloaded Constructor (Simplified)
    public Pizza(String size) {
        this(size, "Thin", new ArrayList<>()); // Chaining to the full constructor
    }

    // ---------- Getters / Setters with Validation ----------

    public void setSize(String size) {
        if (VALID_SIZES.contains(size)) {
            this.size = size;
        } else {
            System.out.println("ERROR: Invalid size '" + size + "'. Options: " + VALID_SIZES);
        }
    }

    public void setCrustType(String crustType) {
        if (VALID_CRUSTS.contains(crustType)) {
            this.crustType = crustType;
        } else {
            System.out.println("ERROR: Invalid crust '" + crustType + "'. Options: " + VALID_CRUSTS);
        }
    }

    public String getSize() { return size; }
    public String getCrustType() { return crustType; }
    public ArrayList<String> getToppings() { return toppings; }
    public int getOrderNo() { return orderNo; }
    public static int getTotalOrders() { return totalOrders; }

    // ---------- Topping Operations ----------

    public void addTopping(String topping) {
        if (!VALID_TOPPINGS.contains(topping)) {
            System.out.println("ERROR: '" + topping + "' is not on the menu.");
            return;
        }
        if (toppings.contains(topping)) {
            System.out.println("ERROR: '" + topping + "' is already added.");
            return;
        }
        if (toppings.size() >= MAX_TOPPINGS) {
            System.out.println("ERROR: Max toppings (3) reached. Cannot add " + topping);
            return;
        }
        toppings.add(topping);
    }

    public void removeTopping(String topping) {
        if (!toppings.remove(topping)) {
            System.out.println("WARNING: " + topping + " not found in this order.");
        }
    }

    // ---------- Price Calculation ----------
    public double calculatePrice() {
        double basePrice = size.equals("Large") ? 89.99 : 49.99;
        return basePrice + (toppings.size() * 5.0);
    }

    // ---------- toString (Override & Overload) ----------
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("╔══════════════════════════════════════╗\n");
        sb.append(String.format("  Order #%d\n", orderNo));
        sb.append("╠══════════════════════════════════════╣\n");
        sb.append(String.format("  Size    : %s\n", size));
        sb.append(String.format("  Crust   : %s\n", crustType));
        sb.append(String.format("  Toppings: %s\n", toppings));
        sb.append("╠══════════════════════════════════════╣\n");
        sb.append(String.format("  TOTAL   : %.2f TL\n", calculatePrice()));
        sb.append("╚══════════════════════════════════════╝");
        return sb.toString();
    }

    public String toString(boolean shortSummary) {
        if (shortSummary) {
            return String.format("[#%d] %s | %.2f TL", orderNo, size, calculatePrice());
        }
        return this.toString();
    }

    // Static Getters for Menu
    public static ArrayList<String> getValidSizes() { return VALID_SIZES; }
    public static ArrayList<String> getValidCrusts() { return VALID_CRUSTS; }
    public static ArrayList<String> getValidToppings() { return VALID_TOPPINGS; }
    public static int getMaxToppings() { return MAX_TOPPINGS; }
}
