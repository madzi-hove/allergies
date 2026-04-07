#include "allergies.h"

// check if allergy has been added before
bool is_false(const allergen_list_t *allergen_list, const allergen_t allergen){
	return allergen_list->allergens[allergen] == 0;
}
// return if allergic to or not
bool is_allergic_to(const allergen_t allergen, const uint16_t score) {
	allergen_list_t allergen_list = get_allergens(score);
    return allergen_list.allergens[allergen];
}

void populate_arr(allergen_list_t *allergens, uint16_t score){
    while (score != 0) {
        if (score >= 128) {
            score -= 128;
            if (is_false(allergens, ALLERGEN_CATS)){
                allergens->allergens[ALLERGEN_CATS] = 1;
                allergens->count++;
            }
        }
        else if (score >= 64) {
            score -= 64;
            if(is_false(allergens, ALLERGEN_POLLEN)){
                allergens->allergens[ALLERGEN_POLLEN] = 1;
                allergens->count++;
            }
        }
        else if (score >= 32) {
            score -= 32;
            if(is_false(allergens, ALLERGEN_CHOCOLATE)){
                allergens->allergens[ALLERGEN_CHOCOLATE] = 1;
                allergens->count++;
            }
        }
        else if (score >= 16) {
            score -= 16;
            if(is_false(allergens, ALLERGEN_TOMATOES)){
                allergens->allergens[ALLERGEN_TOMATOES] = 1;
                allergens->count++;
            }
        }
        else if (score >= 8) {
            score -= 8;
            if(is_false(allergens, ALLERGEN_STRAWBERRIES)){
                allergens->allergens[ALLERGEN_STRAWBERRIES] = 1;
                allergens->count++;
            }
        }
        else if (score >= 4) {
            score -= 4;
            if(is_false(allergens, ALLERGEN_SHELLFISH)){
                allergens->allergens[ALLERGEN_SHELLFISH] = 1;
                allergens->count++;
            }
        }
        else {
            score -= 2;
            if(is_false(allergens, ALLERGEN_PEANUTS)){
                allergens->allergens[ALLERGEN_PEANUTS] = 1;
                allergens->count++;

            }
        }
    }
}

// check and list all allergies represented by score
allergen_list_t get_allergens(const uint16_t score) {
    allergen_list_t temp = {0, {0}};
    uint16_t tmp_score = score;
    if (tmp_score % 2 != 0) {
        tmp_score -= 1;
		if (is_false(&temp, ALLERGEN_EGGS)){
            temp.allergens[ALLERGEN_EGGS] = 1;
            temp.count++;
        }
    }

    
    if (tmp_score > 128 && (tmp_score % 128) == 0) // this condition
        return temp;
    else if (tmp_score >= 128 && (tmp_score % 12) != 0)
        populate_arr(&temp, tmp_score);
    else
        populate_arr(&temp, tmp_score);

    return temp;
}