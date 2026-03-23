public class fanListgen {
    public static void main(String[] args) throws Exception {
        fanList<String> names = new fanList<>();
        names.add("Joey"); names.add("Rachel"); names.add("Chandler");
        System.out.println("--- Friends Names ---");
        names.display();

        fanList<Integer> ages = new fanList<>();
        ages.add(31); ages.add(29); ages.add(30);
        System.out.println("--- Friends Ages ---");
        ages.display();



        
    }

}
