public class App {
    public static void main(String[] args) throws Exception {
        SortedList<Integer> intList  =new SortedList<>();
        intList.add(new Integer[] {10, 5, 8, 3, 3});
        IO.println("Initial List: " + intList);

        intList.uniqueAdd(3);

        intList.delete(3);
        IO.println("After one delete:"+intList);

        SortedList<Double> doubleList = new SortedList<>();
        doubleList.add(5.5);
        doubleList.add(1.2);
        IO.println("Double List: " + doubleList);
    



        

        
    }

}
