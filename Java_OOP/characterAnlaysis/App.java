public class App {
    public static void main(String[] args) {
        friends joey = new friends("Joey Tribbiani", "Actor", "How you doin'?", 19);

        friends rachel = new friends("Rachel Green");
        rachel.setJob("Waitress");
        rachel.setApartmentNumber(20);
        rachel.setCatchyPhrase("Nooooo");

        IO.println("\"--- Character Profiles ---\"");
        IO.println(joey);
        IO.println(rachel);

        IO.println( "Total Characters in System: " + friends.totalCharacters);

    }
}
