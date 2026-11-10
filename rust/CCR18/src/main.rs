use std::io;

fn main() {
    let mut waiting_list: Vec<String> = Vec::new();

    loop {
        let mut customer_name = String::new();

        println!("Customer Name:");

        io::stdin()
            .read_line(&mut customer_name)
            .expect("Input Error");

        customer_name = customer_name.trim().to_string();

        if customer_name == "" {
            println!("Blank names are not allowed.");
            continue;
        }

        waiting_list.push(customer_name);

        let mut answer = String::new();

        println!("Add another customer?");

        io::stdin().read_line(&mut answer).expect("Input Error");

        answer = answer.trim().to_uppercase();

        if answer == "N" {
            break;
        }
    }

    println!();
    println!("----------------------------------------");
    println!("Harbor View Restaurant Waiting List Summary");
    println!("Version 1.0");
    println!("----------------------------------------");
    println!("Customers Waiting");

    let mut index = 0;

    while index < waiting_list.len() {
        println!("{}. {}", index + 1, waiting_list[index]);
        index += 1;
    }

    println!("----------------------------------------");

    println!("Total Customers : {}", waiting_list.len());

    if waiting_list.len() > 0 {
        println!("First Customer : {}", waiting_list[0]);
        println!("Last Customer : {}", waiting_list[waiting_list.len() - 1]);
    } else {
        println!("First Customer : None");
        println!("Last Customer : None");
    }

    println!("Waiting list completed successfully.");
}
