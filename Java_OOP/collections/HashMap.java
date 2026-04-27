import java.util.HashMap;
import java.util.Map;

/**
 * Demonstrates the usage of HashMap for Key-Value mapping.
 * Part of the daily coding exercises focusing on Data Structures.
 */
public class App {
    public static void main(String[] args) {
        System.out.println("Dictionary Application Started...");

        // Using Map interface as a reference for better flexibility (Senior practice)
        Map<String, String> dictionary = new HashMap<>();

        // Adding key-value pairs
        dictionary.put("book", "kitap");
        dictionary.put("table", "masa");
        dictionary.put("computer", "bilgisayar");

        // Displaying the number of entries
        System.out.println("Dictionary Size: " + dictionary.size());

        // Iterating through values (Printing Turkish meanings)
        System.out.println("--- All Meanings ---");
        for (String meaning : dictionary.values()) {
            System.out.println("Meaning: " + meaning);
        }

        // Retrieving a specific value by its key
        String searchKey = "computer";
        System.out.println("Search for '" + searchKey + "': " + dictionary.get(searchKey));

        // Removing an entry
        dictionary.remove("computer");
        System.out.println("After removing 'computer', size: " + dictionary.size());

        // Clearing the dictionary
        dictionary.clear();
        System.out.println("Final Dictionary Status (Cleared): " + dictionary);
    }
}
