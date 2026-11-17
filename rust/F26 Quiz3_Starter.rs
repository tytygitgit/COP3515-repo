// Quiz 3 starter program: University Bookstore
// Modified to add discount, tax, and most expensive book.
use std::fs;
use std::io::{self, Write};

const MAX_ITEMS: usize = 10;
const RECEIPT_FILE: &str = "receipt.txt";

fn read_line(prompt: &str) -> String {
    print!("{prompt}");
    io::stdout().flush().expect("Could not flush output");

    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Could not read input");

    input.trim().to_string()
}

fn calculate_total(items: &Vec<(String, f64)>) -> f64 {
    let mut total = 0.0;

    for item in items {
        total += item.1;
    }

    total
}

fn main() {
    let store_name = String::from("USF Bookstore");
    let categories = ["Fiction", "Science", "History"];

    println!(
        "{} | Categories: {}, {}, {}",
        store_name, categories[0], categories[1], categories[2]
    );

    let mut items: Vec<(String, f64)> = Vec::new();
    let mut keep_going = true;

    while keep_going && items.len() < MAX_ITEMS {
        let name = read_line("Book name (or 'done'): ");

        if name.to_lowercase() == "done" {
            keep_going = false;
        } else if name.len() == 0 {
            println!("Book name cannot be blank.");
        } else {
            let price: f64 = loop {
                let price_text = read_line("Price in dollars: ");

                match price_text.parse::<f64>() {
                    Ok(value) if value >= 0.0 => break value,
                    Ok(_) => println!("Price cannot be negative."),
                    Err(_) => println!("Enter a numeric price, such as 12.50."),
                }
            };

            items.push((name, price));
        }
    }

    let subtotal = calculate_total(&items);
    let item_count = items.len();

    // 10% discount for 5 or more books
    let discount_amount = if item_count >= 5 {
        subtotal * 0.10
    } else {
        0.0
    };

    let discounted_subtotal = subtotal - discount_amount;

    // 7% sales tax after discount
    let tax_amount = discounted_subtotal * 0.07;

    let final_total = discounted_subtotal + tax_amount;

    // Find most expensive book
    let mut most_expensive_name = String::from("N/A");
    let mut most_expensive_price = 0.0;

    if !items.is_empty() {
        most_expensive_name = items[0].0.clone();
        most_expensive_price = items[0].1;

        for item in &items {
            if item.1 > most_expensive_price {
                most_expensive_price = item.1;
                most_expensive_name = item.0.clone();
            }
        }
    }

    let mut receipt = String::new();

    receipt.push_str(&format!("{store_name}\n"));

    for (name, price) in &items {
        receipt.push_str(&format!("{name}: ${price:.2}\n"));
    }

    receipt.push_str(&format!("Items: {item_count}\n"));
    receipt.push_str(&format!("Subtotal: ${subtotal:.2}\n"));
    receipt.push_str(&format!("Discount: ${discount_amount:.2}\n"));
    receipt.push_str(&format!("Sales Tax: ${tax_amount:.2}\n"));
    receipt.push_str(&format!("Final Total: ${final_total:.2}\n"));

    if item_count > 0 {
        receipt.push_str(&format!(
            "Most Expensive: {} (${:.2})\n",
            most_expensive_name, most_expensive_price
        ));
    } else {
        receipt.push_str("Most Expensive: N/A\n");
    }

    println!("\n{receipt}");

    fs::write(RECEIPT_FILE, &receipt).expect("Could not write receipt");

    let saved_receipt = fs::read_to_string(RECEIPT_FILE).expect("Could not read saved receipt");

    println!("Saved {} bytes to {}.", saved_receipt.len(), RECEIPT_FILE);

    let transaction_ready = item_count > 0 && subtotal >= 0.0;
    let needs_review = !transaction_ready || subtotal > 500.0;

    if transaction_ready {
        println!("Transaction ready.");
    } else {
        println!("No books were entered.");
    }

    if needs_review {
        println!("This transaction needs review.");
    } else {
        println!("No additional review is needed.");
    }

    let transaction_size = match item_count {
        0 => "Empty",
        1..=4 => "Small",
        _ => "Large",
    };

    println!("Transaction size: {transaction_size}");
}
