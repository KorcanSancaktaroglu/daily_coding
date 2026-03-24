import java.util.ArrayList;
public class CatalogManager {
    private ArrayList<Product> products = new ArrayList<>();
    public void addProduct(Product p){
        products.add(p);

    }
    //Method to list all products
    public void listAllProducts(){
        IO.println("\n---All Products---\n");
        for(Product p :products ){
            IO.println(p);
        }
    }
    //Filter by category
    public void filterByCategory(String category){
        IO.println("\n---Filtering category :"+category+"--");
        for(Product p : products){
            if(p.getCategory()==category){
                IO.println(p);
            }
        }
    }
    public void searchByPriceRange(double min,double max){
        IO.println("\n---Products Between "+min +" and"+max);
        for(Product p:products){
            if(p.getPrice() >min && p.getPrice()<max) IO.println(p);
        }
    }
    //calculate total value of stock
    public double calculateTotalStockValue(){
        double total=0;
        for (Product p:products){
            total+=  p.getPrice()* p.geStock();
        }
        return total;


    }


    
}
