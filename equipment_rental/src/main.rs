fn main() {
    // Equipment Record #1
    let equipment_id_1 = 1001;
    let equipment_name_1 = "Laptop";
    let category_1 = "Computer";
    let available_1 = true;

    // Equipment Record #2
    let equipment_id_2 = 1002;
    let equipment_name_2 = "Camera";
    let category_2 = "Photography";
    let available_2 = true;

    // Equipment Record #3
    let equipment_id_3 = 1003;
    let equipment_name_3 = "Projector";
    let category_3 = "Classroom";
    let available_3 = false;

    println!("------------------------------------------------");
    println!("University Equipment Rental System");
    println!("Version 1.0");
    println!("------------------------------------------------");

    println!("\nEquipment Inventory\n");

    println!("ID:          {}", equipment_id_1);
    println!("Name:        {}", equipment_name_1);
    println!("Category:    {}", category_1);

    if available_1 {
        println!("Available:   Yes");
    } else {
        println!("Available:   No");
    }

    println!();

    println!("ID:          {}", equipment_id_2);
    println!("Name:        {}", equipment_name_2);
    println!("Category:    {}", category_2);

    if available_2 {
        println!("Available:   Yes");
    } else {
        println!("Available:   No");
    }

    println!();

    println!("ID:          {}", equipment_id_3);
    println!("Name:        {}", equipment_name_3);
    println!("Category:    {}", category_3);

    if available_3 {
        println!("Available:   Yes");
    } else {
        println!("Available:   No");
    }
}
