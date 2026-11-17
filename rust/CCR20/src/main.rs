use std::io;

fn main() {
    let mut paragraph = String::new();

    // Paragraph Input Validation
    loop {
        paragraph.clear();

        println!("Enter Paragraph:");

        io::stdin().read_line(&mut paragraph).expect("Input Error");

        paragraph = paragraph.trim().to_string();

        if paragraph.is_empty() {
            println!("ERROR: Paragraph cannot be empty.");
        } else {
            break;
        }
    }

    // Word Count
    let words: Vec<&str> = paragraph.split_whitespace().collect();

    let word_count = words.len();

    // Maximum Paragraph Size Check
    if word_count > 500 {
        println!("ERROR: Paragraph exceeds 500 words.");
        return;
    }

    // Character Count (letters and numbers only)
    let mut character_count = 0;

    for ch in paragraph.chars() {
        if ch.is_alphanumeric() {
            character_count += 1;
        }
    }

    // Longest Word
    let mut longest_word: &str = "";

    for word in &words {
        if word.len() > longest_word.len() {
            longest_word = word;
        }
    }

    // Average Word Length
    let mut total_letters = 0;

    for word in &words {
        let mut clean_length = 0;

        for ch in word.chars() {
            if ch.is_alphanumeric() {
                clean_length += 1;
            }
        }

        total_letters += clean_length;
    }

    let average_word_length: f64;

    if word_count > 0 {
        average_word_length = total_letters as f64 / word_count as f64;
    } else {
        average_word_length = 0.0;
    }

    // Summary Report
    println!();
    println!("----------------------------------------");
    println!("Precision Document Editing Services");
    println!("Document Analysis Summary Version 1.0");
    println!("----------------------------------------");

    println!("Characters         : {}", character_count);
    println!("Words              : {}", word_count);
    println!("Longest Word       : {}", longest_word);
    println!("Average Word Length: {:.2}", average_word_length);

    println!();
    println!("Original Paragraph:");
    println!("{}", paragraph);

    println!();
    println!("Analysis completed successfully.");
}
