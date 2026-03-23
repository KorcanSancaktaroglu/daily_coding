import java.util.Collections;
import java.util.ArrayList;
public class SortedList<T extends Comparable<T>> {
    private ArrayList<T> items; // placeholder

    public SortedList() {
        this.items = new ArrayList<>();
    }

    // A helper method to show the list content
    @Override
    public String toString() {
        return items.toString();
    }
    public void add(T nItem){
        items.add(nItem);
        Collections.sort(items); // // Re-sorts the list automatically

    }
    public void add(T[] itemArray){
        for(T item:itemArray){
            add(item);
        }


    }
    public void uniqueAdd(T nItem){
        if(!items.contains(nItem)){
            add(nItem); return;

        }
        IO.println("System Message: "+ nItem +" alread exits in items");
    }
    public void delete(T nItem){
        if(items.contains(nItem)){
            items.remove(nItem);
            IO.println("Item: "+nItem+" removed.");
            return ;
        }
        else{
            IO.println("Error: " + nItem + " not found in the list.");
        }
    }
    public void deleteAll(T nItem){
        if(!items.contains(nItem)){
            IO.println("Error: nothing to delete"); return ;
        }
        while(items.contains(nItem)){
            items.remove(nItem);
        }
        IO.println("System: All instances of \" + item + \" have been cleared.");
    }
}
