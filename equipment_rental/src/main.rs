use std::fs;

fn main() {
    println!("------------------------------------------------");
    println!("University Equipment Rental System");
    println!("Version 2.0");
    println!("------------------------------------------------");
    println!("\nEquipment Inventory\n");

    let file_contents = match fs::read_to_string("equipment.txt") {
        Ok(contents) => contents,
        Err(_) => {
            println!("ERROR");
            println!("Unable to open equipment.txt");
            println!("Please verify that the file exists.");
            return;
        }
    };

    for line in file_contents.lines() {
        if line.trim().is_empty() {
            continue;
        }

        let parts: Vec<&str> = line.split(',').collect();

        if parts.len() != 4 {
            println!("ERROR: Invalid equipment record\n");
            continue;
        }

        let equipment_id = parts[0].trim();
        let equipment_name = parts[1].trim();
        let category = parts[2].trim();
        let available = parts[3].trim();

        if equipment_id.parse::<u32>().is_err() {
            println!("ERROR: Invalid equipment record\n");
            continue;
        }

        if equipment_name.is_empty() || category.is_empty() {
            println!("ERROR: Invalid equipment record\n");
            continue;
        }

        let available_bool = match available {
            "true" => true,
            "false" => false,
            _ => {
                println!("ERROR: Invalid equipment record\n");
                continue;
            }
        };

        println!("ID:          {}", equipment_id);
        println!("Name:        {}", equipment_name);
        println!("Category:    {}", category);

        if available_bool {
            println!("Available:   Yes");
        } else {
            println!("Available:   No");
        }

        println!();
    }
}
