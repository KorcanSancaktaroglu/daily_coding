import java.util.List;
import java.util.ArrayList;
public class fanList<T> {
    ArrayList<T> items;
    public fanList(){
        items = new ArrayList<>();

    }
    public void add(T item){
        items.add(item);


    }
    public void display(){
        
        for(T item:items){
            IO.println("Fan Data:"+item);
        }
        IO.println("---------------");

    }
    

    
}
