import java.util.ArrayList;
import java.util.List;

/**
 * Demonstrates ArrayList operations with Type Safety.
 * Part of the daily coding exercises.
 */
public class App {
    public static void main(String[] args) {
        System.out.println("ArrayList Operations Started...");

        // Using Generics <Integer> to ensure Type Safety
        List<Object> elements = new ArrayList<>();
        
        System.out.println("Initial Size: " + elements.size());

        // Adding a single element
        elements.add(1);

        // Adding multiple elements from an array
        int[] itemsToAdd = {3, 4};
        for (int item : itemsToAdd) {
            elements.add(item);
        }
        System.out.println("Numbers added.");

        // Adding a String (Valid because we used List<Object>)
        elements.add("Ankara");

        System.out.println("Current Size: " + elements.size());
        System.out.println("Element at index 3: " + elements.get(3));

        // Update (Set) element at index 3
        elements.set(3, 100);

        // Remove element at index 0 (Shifting occurs here)
        elements.remove(0);

        // Clear all elements
        elements.clear();
        
        // Note: Accessing index 0 after clear() will throw IndexOutOfBoundsException
        // System.out.println(elements.get(0)); 
    }
}
