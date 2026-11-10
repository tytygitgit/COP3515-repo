use std::io;

const TAX_RATE: f64 = 0.062;
const OVERTIME_LIMIT: f64 = 40.0;
const OVERTIME_MULTIPLIER: f64 = 1.5;

fn main() {
    // Employee Name Input
    let mut employee_name = String::new();

    loop {
        employee_name.clear();

        println!("Enter Employee Name:");

        io::stdin()
            .read_line(&mut employee_name)
            .expect("Input Error");

        employee_name = employee_name.trim().to_string();

        if employee_name.is_empty() {
            println!("ERROR: Employee name cannot be blank.");
        } else {
            break;
        }
    }

    // Hours Worked Input
    let hours_worked: f64;

    loop {
        let mut input = String::new();

        println!("Enter Hours Worked:");

        io::stdin().read_line(&mut input).expect("Input Error");

        match input.trim().parse::<f64>() {
            Ok(value) if value >= 0.0 => {
                hours_worked = value;
                break;
            }

            _ => {
                println!("ERROR: Enter a valid number that is 0 or greater.");
            }
        }
    }

    // Hourly Rate Input
    let hourly_rate: f64;

    loop {
        let mut input = String::new();

        println!("Enter Hourly Pay Rate:");

        io::stdin().read_line(&mut input).expect("Input Error");

        match input.trim().parse::<f64>() {
            Ok(value) if value >= 0.0 => {
                hourly_rate = value;
                break;
            }

            _ => {
                println!("ERROR: Enter a valid pay rate that is 0 or greater.");
            }
        }
    }

    // Payroll Date Input
    let mut payroll_date = String::new();

    loop {
        payroll_date.clear();

        println!("Enter Payroll Date (MM/DD/YYYY):");

        io::stdin()
            .read_line(&mut payroll_date)
            .expect("Input Error");

        payroll_date = payroll_date.trim().to_string();

        if payroll_date.is_empty() {
            println!("ERROR: Date cannot be blank.");
        } else {
            break;
        }
    }

    // Payroll Calculations
    let overtime_pay;
    let gross_pay;

    if hours_worked > OVERTIME_LIMIT {
        overtime_pay = (hours_worked - OVERTIME_LIMIT) * hourly_rate * OVERTIME_MULTIPLIER;

        gross_pay = (OVERTIME_LIMIT * hourly_rate) + overtime_pay;
    } else {
        overtime_pay = 0.0;

        gross_pay = hours_worked * hourly_rate;
    }

    let taxes_withheld = gross_pay * TAX_RATE;

    let net_pay = gross_pay - taxes_withheld;

    // Payroll Summary
    println!();
    println!("----------------------------------------");
    println!("Sunshine Payroll Services");
    println!("Weekly Payroll Summary Version 1.0");
    println!("----------------------------------------");

    println!("Date             : {}", payroll_date);
    println!("Employee         : {}", employee_name);
    println!("Hours Worked     : {:.2}", hours_worked);
    println!("Hourly Rate      : ${:.2}", hourly_rate);
    println!("Gross Pay        : ${:.2}", gross_pay);
    println!("Overtime Pay     : ${:.2}", overtime_pay);
    println!("Taxes Withheld   : ${:.2}", taxes_withheld);
    println!("Net Pay          : ${:.2}", net_pay);
}
