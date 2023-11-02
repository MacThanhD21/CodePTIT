import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Product {
    private String code;
    private String name;
    private int price;
    private int warranty;

    public Product(String code, String name, int price, int warranty) {
        this.code = code;
        this.name = name;
        this.price = price;
        this.warranty = warranty;
    }

    public String getCode() {
        return code;
    }

    public String getName() {
        return name;
    }

    public int getPrice() {
        return price;
    }
    public int getWarranty() {
        return warranty;
    }
}

public class J07048 {
    public static void main(String[] args) throws FileNotFoundException{
        ArrayList<Product> products = new ArrayList<>();
        // Scanner scanner = new Scanner(new File("SANPHAM.in"));
        Scanner scanner = new Scanner(System.in);

        int numProducts = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < numProducts; i++) {
            String code = scanner.nextLine();
            String name = scanner.nextLine();
            int price = Integer.parseInt(scanner.nextLine());
            int warranty = Integer.parseInt(scanner.nextLine());

            Product product = new Product(code, name, price, warranty);
            products.add(product);
        }

        // Sắp xếp danh sách sản phẩm
        Collections.sort(products, new Comparator<Product>() {
            @Override
            public int compare(Product p1, Product p2) {
                // So sánh theo giá bán giảm dần
                if (p1.getPrice() > p2.getPrice()) {
                    return -1;
                } else if (p1.getPrice() < p2.getPrice()) {
                    return 1;
                } else {
                    // Nếu giá bán bằng nhau, sắp xếp theo mã sản phẩm (thứ tự từ điển)
                    return p1.getCode().compareTo(p2.getCode());
                }
            }
        });

        // In danh sách sản phẩm đã sắp xếp
        for (Product product : products) {
            System.out.println(product.getCode() + " " + product.getName() + " " + product.getPrice() + " " + product.getWarranty());
        }
    }
}