public class Product {
    private String _name,_category;
    private double _price;
    private int _stock;
    public Product(String name,String category,double price,int stock){
        _category = category;
        _name= name;
        _price = price;
        _stock = stock;
    }
    public String getName(){return _name;} 
    public String getCategory(){return _category;}
    public double getPrice() {return _price;}
    public int geStock() {return _stock;}
    @Override
    public String toString(){
        return String.format("Product: %-15s | Category: %-10s | Price: %7.2f | Stock: %d", 
                             _name, _category, _price, _stock);
    }
    
}
