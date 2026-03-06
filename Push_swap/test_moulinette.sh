#!/bin/bash
EXEC="/home/vblanco-/Documents/Tronc-Commum/Push-Swap/PS-swap/Push_swap/push_swap"

echo "================================================="
echo "    MOULINETTE TEST SUITE (34 TESTS INTENSIFS)   "
echo "================================================="

# Couleurs pour le terminal
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

test_error() {
    name=$1
    shift
    res=$($EXEC "$@" 2>&1)
    if [ "$res" = "Error" ]; then
        echo -e "${GREEN}✅ $name : ERROR CAUGHT${NC}"
    else
        echo -e "${RED}❌ $name : FAILED (Output was: '$res')${NC}"
    fi
}

test_empty() {
    name=$1
    shift
    res=$($EXEC "$@" 2>&1)
    if [ -z "$res" ]; then
        echo -e "${GREEN}✅ $name : SILENT (OK)${NC}"
    else
        echo -e "${RED}❌ $name : FAILED (Output was: '$res')${NC}"
    fi
}

test_bench() {
    name=$1
    shift
    res=$($EXEC --bench "$@" 2>&1)
    ops=$(echo "$res" | grep -E "Total operations" | awk -F ':' '{print $2}' | tr -d ' ')
    status=$(echo "$res" | grep -E "Trié|caca")
    if echo "$status" | grep -q "Trié"; then
        echo -e "📊 $name : ${GREEN}$ops ops${NC} | Status: ${GREEN}$status${NC}"
    else
        echo -e "📊 $name : $ops ops | Status: ${RED}$status${NC}"
    fi
}

echo -e "\n--- 🚨 PARTIE 1 : TESTS D'ERREURS (Doit afficher 'Error') ---"
test_empty "1. Aucun argument"
test_error "2. Chaine vide" ""
test_error "3. Espace seul" " "
test_error "4. Non numérique (1 a 2)" "1 a 2"
test_error "5. Doublon simple (1 2 2)" "1 2 2"
test_error "6. Doublon lointain (5 1 2 3 5)" "5 1 2 3 5"
test_error "7. Overflow (> INT_MAX)" "2147483648"
test_error "8. Underflow (< INT_MIN)" "-2147483649"
test_error "9. Max Long (ne doit pas loop en int)" "999999999999"
test_error "10. Signe '-' seul" "-"
test_error "11. Signe '+' seul" "+"
test_error "12. Mauvais format interne (1-2)" "1-2"
test_error "13. Double signe (--1)" "--1"
test_error "14. Chaine avec texte collé (123a)" "1 2 123a 4"

echo -e "\n--- 🚧 PARTIE 2 : LIMITES VALIDES (Ne doit pas crasher/erreur) ---"
test_empty "15. Limites INT (2147483647 -2147483648 0)" 2147483647 -2147483648 0

echo -e "\n--- 🧘 PARTIE 3 : TESTS DEJA TRIES (Ne doit rien afficher) ---"
test_empty "16. Un seul nombre" "42"
test_empty "17. Deux nombres triés" "1 2"
test_empty "18. Trois nombres triés" "1 2 3"
test_empty "19. Cinq nombres triés" "1 2 3 4 5"
test_empty "20. 10 nombres triés" "-5 -4 -3 -2 -1 0 1 2 3 4"

echo -e "\n--- 🎲 PARTIE 4 : MATRICE 3 NOMBRES (< 3 ops) ---"
test_bench "21. (1 3 2)" 1 3 2
test_bench "22. (2 1 3)" 2 1 3
test_bench "23. (2 3 1)" 2 3 1
test_bench "24. (3 1 2)" 3 1 2
test_bench "25. (3 2 1)" 3 2 1

echo -e "\n--- 🎯 PARTIE 5 : MATRICE 5 NOMBRES (< 12 ops requises) ---"
test_bench "26. Random 1" 5 1 4 2 3
test_bench "27. Random 2" 1 5 2 4 3
test_bench "28. Pire cas (Inversé)" 5 4 3 2 1

echo -e "\n--- 🚀 PARTIE 6 : MOULINETTE 100 NOMBRES (< 700 ops) ---"
ARG100=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
test_bench "29. 100 nombres (Essai 1)" $ARG100
ARG100_2=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
test_bench "30. 100 nombres (Essai 2)" $ARG100_2
test_bench "31. 100 nombres (Pire cas : inversé)" $(seq 100 -1 1 | tr '\n' ' ')

echo -e "\n--- 🔥 PARTIE 7 : MOULINETTE 500 NOMBRES (< 5500 ops) ---"
ARG500=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
test_bench "32. 500 nombres (Essai 1)" $ARG500
ARG500_2=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
test_bench "33. 500 nombres (Essai 2)" $ARG500_2
test_bench "34. 500 nombres (Pire cas : inversé)" $(seq 500 -1 1 | tr '\n' ' ')

echo -e "\n================================================="
echo "                  TESTS TERMINÉS                 "
echo "================================================="
