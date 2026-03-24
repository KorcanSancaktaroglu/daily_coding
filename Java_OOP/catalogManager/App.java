public class App {
    public static void main(String[] args) throws Exception {
        CatalogManager catalog = new CatalogManager();
        catalog.addProduct(new Product("Laptop","Electronics",12000.0,5));
        catalog.addProduct(new Product("Phone","Electornics",800.0,10));
        catalog.addProduct(new Product("Desk","Furniture",150.0,3));
        catalog.addProduct(new Product("Chair","Furniture",85.0,12));
        catalog.addProduct(new Product("headphones","Electronics",120.0,15));

        catalog.listAllProducts();
        catalog.filterByCategory("Electronics");
        catalog.searchByPriceRange(100,900 );

    }
}
