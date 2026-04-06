#include "allergies.h"

bool is_false(const allergen_list_t allergen_list, const allergen_t allergen){
	return allergen_list.allergens[allergen] == 0;
}

bool is_allergic_to(const allergen_t allergen, const unsigned int score) {
	allergen_list_t allergen_list = get_allergens(score);
    return allergen_list.allergens[allergen];
}

allergen_list_t get_allergens(const unsigned int score) {
    allergen_list_t temp = {0, {0}};
    int tmp_score = score;
    if (tmp_score % 2 != 0) {
        tmp_score -= 1;
		if (is_false(temp, ALLERGEN_EGGS)){
            temp.allergens[ALLERGEN_EGGS] = 1;
            temp.count++;
        }
    }
while (tmp_score != 0) {
    if (tmp_score >= 128) {
        tmp_score -= 128;
		if (is_false(temp, ALLERGEN_CATS)){
            temp.allergens[ALLERGEN_CATS] = 1;
            temp.count++;
        }
    }
    else if (tmp_score >= 64) {
        tmp_score -= 64;
        if(is_false(temp, ALLERGEN_POLLEN)){
            temp.allergens[ALLERGEN_POLLEN] = 1;
            temp.count++;
        }
    }
    else if (tmp_score >= 32) {
        tmp_score -= 32;
        if(is_false(temp, ALLERGEN_CHOCOLATE)){
            temp.allergens[ALLERGEN_CHOCOLATE] = 1;
            temp.count++;
        }
    }
    else if (tmp_score >= 16) {
        tmp_score -= 16;
        if(is_false(temp, ALLERGEN_TOMATOES)){
            temp.allergens[ALLERGEN_TOMATOES] = 1;
            temp.count++;
        }
    }
    else if (tmp_score >= 8) {
        tmp_score -= 8;
        if(is_false(temp, ALLERGEN_STRAWBERRIES)){
            temp.allergens[ALLERGEN_STRAWBERRIES] = 1;
            temp.count++;
        }
    }
    else if (tmp_score >= 4) {
        tmp_score -= 4;
        if(is_false(temp, ALLERGEN_SHELLFISH)){
            temp.allergens[ALLERGEN_SHELLFISH] = 1;
            temp.count++;
        }
    }
    else {
        tmp_score -= 2;
        if(is_false(temp, ALLERGEN_PEANUTS)){
            temp.allergens[ALLERGEN_PEANUTS] = 1;
            temp.count++;

        }
    }
}
    return temp;
}