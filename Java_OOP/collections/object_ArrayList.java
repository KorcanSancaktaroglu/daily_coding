import java.util.ArrayList;
import java.util.List;

/**
 * Customer entity class with Encapsulation.
 */
class Customer {
    private int id;
    private String firstName;
    private String lastName;

    // Default Constructor
    public Customer() {
    }

    // Parameterized Constructor
    public Customer(int id, String firstName, String lastName) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    // Getters and Setters (Essential for professional Java entities)
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getFirstName() { return firstName; }
    public void setFirstName(String firstName) { this.firstName = firstName; }

    public String getLastName() { return lastName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
}

public class App {
    public static void main(String[] args) {
        System.out.println("Customer Management System Started...");

        // Type-safe List using the Customer entity
        List<Customer> customers = new ArrayList<>();

        // Adding a new customer record
        customers.add(new Customer(1, "Engin", "Demiroğ"));

        // Example: Iterating through the customer list
        for (Customer customer : customers) {
            System.out.println("Customer ID: " + customer.getId() + 
                               " | Name: " + customer.getFirstName() + " " + customer.getLastName());
        }
    }
}
