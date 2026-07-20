-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Find the crime scene report
SELECT description FROM crime_scene_reports
WHERE year = 2025 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- Find interviews mentioning the bakery
SELECT name, transcript FROM interviews
WHERE year = 2025 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- Check who exited the bakery parking lot within 10 minutes of the theft (10:15am)
SELECT name, hour, minute, bakery_security_logs.license_plate FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2025 AND month = 7 AND day = 28
AND activity = "exit"
AND hour = 10 AND minute BETWEEN 15 AND 25
ORDER BY minute;

-- Check who withdrew cash at the Leggett Street ATM that morning
SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2025
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";

-- Get phone numbers of overlapping suspects
SELECT name, phone_number FROM people WHERE name IN ("Bruce", "Diana", "Iman", "Luca");

-- Find short phone calls (<60 sec) made that day
SELECT caller, receiver, duration FROM phone_calls
WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60;

-- Identify who Bruce and Diana called
SELECT name, phone_number FROM people WHERE phone_number IN ("(375) 555-8161", "(725) 555-3243");

-- Find the earliest flight out on July 29, 2025
SELECT id, hour, minute, origin_airport_id, destination_airport_id FROM flights
WHERE year = 2025 AND month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 1;

-- Confirm Bruce and Robin were passengers on that flight
SELECT people.name, flights.destination_airport_id FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
AND people.name IN ("Bruce", "Robin");

-- Confirm the destination city
SELECT city FROM airports WHERE id = 4;
