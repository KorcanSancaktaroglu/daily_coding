import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileOperations {

    // Using a relative path makes the code work on any computer
    private static final String FILE_PATH = "test_file.txt";

    public static void createFile() {
        File file = new File(FILE_PATH);
        try {
            if (file.createNewFile()) {
                System.out.println("Success: File created.");
            } else {
                System.out.println("Info: File already exists.");
            }
        } catch (IOException e) {
            System.out.println("Error: Could not create file.");
            e.printStackTrace();
        }
    }

    public static void getFileInfo() {
        File file = new File(FILE_PATH);
        if (file.exists()) {
            System.out.println("\n--- File Information ---");
            System.out.println("File Name    : " + file.getName());
            System.out.println("Absolute Path: " + file.getAbsolutePath());
            System.out.println("Writable     : " + file.canWrite());
            System.out.println("Readable     : " + file.canRead());
            System.out.println("File Size    : " + file.length() + " bytes");
            System.out.println("------------------------\n");
        } else {
            System.out.println("Error: File does not exist, cannot fetch info.");
        }
    }

    public static void readFile() {
        File file = new File(FILE_PATH);
        // try-with-resources automatically closes the scanner
        try (Scanner reader = new Scanner(file)) {
            System.out.println("--- File Content ---");
            while (reader.hasNextLine()) {
                String line = reader.nextLine();
                System.out.println(line);
            }
            System.out.println("--------------------\n");
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found for reading.");
            e.printStackTrace();
        }
    }

    public static void writeFile() {
        // 'true' parameter enables append mode
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH, true))) {
            writer.newLine();
            writer.write("New data entry added by Java!");
            System.out.println("Success: Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("Error: Could not write to file.");
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        System.out.println("Starting File Operations...\n");
        
        createFile();
        getFileInfo();
        writeFile(); // Adds new line
        readFile();  // Reads the updated file
    }
}
