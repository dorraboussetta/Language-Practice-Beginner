#include <stdio.h>
#include <stdlib.h>

/*
 * Health Insurance Risk & Offer Program
 *
 * This program simulates how an insurance company evaluates a potential client
 * and offers them suitable health insurance levels depending on:
 *   - Their year of birth (used to calculate age)
 *   - Height and weight (used to calculate BMI)
 *   - Medical history (surgery, work stoppage, viral serology screening)
 *   - Their maximum available budget
 *
 * Clients are classified as:
 *   - High risk (membership rejected)
 *   - Medium risk (15% surcharge on contributions)
 *   - Low risk (basic contribution rates)
 *
 * Depending on the risk and the client’s budget, the program displays
 * possible insurance levels (Level 1, 2, 3) and their contribution rates,
 * then allows the client to choose one level and shows detailed ceilings
 * for that level.
 */

int main()
{
    // === Input variables ===
    int birth_year, i, sw, st, risk_level, chosen_level=0;
    float height, weight, budget_max, BMI;

    // === Collect user input ===
    printf("Enter the year of birth: \n"); 
    scanf("%d", &birth_year);

    printf("Enter your height (in meters): \n"); 
    scanf("%f", &height);

    printf("Enter your weight (in kg): \n"); 
    scanf("%f", &weight);

    printf("Have you had a surgical intervention in the last 10 years (1 if yes, 0 if no): \n"); 
    scanf("%d", &i);

    printf("Have you had a work stoppage of more than a month during the last 5 years (1 if yes, 0 if no): \n"); 
    scanf("%d", &sw);

    printf("What is your viral serology screening (0 if none, 1 if HAV, 2 if HBV, 3 if HCV, 4 if HIV): \n");
    scanf("%d", &st);

    printf("What is your maximum budget: \n"); 
    scanf("%f", &budget_max);

    // === Calculate BMI ===
    BMI = weight / (height * height);

    // === Risk assessment ===
    // High risk: surgery OR work stoppage OR HBV/HCV/HIV
    if (i==1 || sw==1 || st==2 || st==3 || st==4)
    {
        risk_level = 3;
        printf("Membership request rejected.\n");
        return 0;   // Stop program for high-risk clients
    }
    // Medium risk: age > 50 OR HAV OR abnormal BMI
    else if ((2025 - birth_year) > 50 || st==1 || BMI < 16.5 || BMI > 30)
        risk_level = 2;
    // Otherwise → Low risk
    else 
        risk_level = 1;

    // === Offers section ===
    // Both low and medium risk clients can get offers
    float multiplier = (risk_level == 2) ? 1.15 : 1.0;  // 15% extra if medium risk

    // Check available levels depending on budget
    if (budget_max >= 2100 * multiplier) {
        // Client can afford all 3 levels
        printf("Level 1: benefits = 3000 TD, Contribution = %.0f DT\n", 1500 * multiplier);
        printf("Level 2: benefits = 3500 TD, Contribution = %.0f DT\n", 1800 * multiplier);
        printf("Level 3: benefits = 5000 TD, Contribution = %.0f DT\n", 2100 * multiplier);
        printf("Choose 1, 2 or 3: "); 
        scanf("%d", &chosen_level);
    }
    else if (budget_max >= 1800 * multiplier) {
        // Client can afford levels 1 and 2
        printf("Level 1: benefits = 3000 TD, Contribution = %.0f DT\n", 1500 * multiplier);
        printf("Level 2: benefits = 3500 TD, Contribution = %.0f DT\n", 1800 * multiplier);
        printf("Choose 1 or 2: "); 
        scanf("%d", &chosen_level);
    }
    else if (budget_max >= 1500 * multiplier) {
        // Client can only afford level 1
        printf("Level 1: benefits = 3000 TD, Contribution = %.0f DT\n", 1500 * multiplier);
        chosen_level = 1;
    }
    else {
        // Budget too low for any level
        printf("Sorry, your budget is too low for any available level.\n");
        return 0;
    }

    // === Final details for chosen level ===
    if (chosen_level == 1) {
        printf("Level 1 Details:\n");
        printf("Consultations: 20 TD / act\nMedications: 400 DT\nAnalyses: 150 DT\nRadiology: 180 DT\nSurgery: 1500 DT\n");
        printf("Maximum reimbursed services = 3000 TD per provider and per year\n");
    }
    else if (chosen_level == 2) {
        printf("Level 2 Details:\n");
        printf("Consultations: 30 TD / act\nMedications: 600 DT\nAnalyses: 200 DT\nRadiology: 250 DT\nSurgery: 1800 DT\n");
        printf("Maximum reimbursed services = 3500 TD per provider and per year\n");
    }
    else if (chosen_level == 3) {
        printf("Level 3 Details:\n");
        printf("Consultations: 40 TD / act\nMedications: 600 DT\nAnalyses: 300 DT\nRadiology: 300 DT\nSurgery: 2000 DT\n");
        printf("Maximum reimbursed services = 5000 TD per provider and per year\n");
    }

    return 0;
}
