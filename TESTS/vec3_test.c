#include <stdio.h>
#include "vec3.h"

int main(void)
{
    // Vetores de teste
    vec3 a = vec3_new(1.0, 2.0, 3.0);
    vec3 b = vec3_new(4.0, 5.0, 6.0);

    printf("=== Teste de Funções Vec3 ===\n");

    // Teste vec3_sum
    vec3 sum = vec3_sum(&a, &b);
    printf("Soma a+b: ");
    vec3_print(&sum); // esperado: (5, 7, 9)

    // Teste vec3_sub
    vec3 sub = vec3_new(
        vec3_x(&a) - vec3_x(&b),
        vec3_y(&a) - vec3_y(&b),
        vec3_z(&a) - vec3_z(&b)
    );
    printf("Subtracao a-b: ");
    vec3_print(&sub); // esperado: (-3, -3, -3)

    // Teste vec3_scale
    vec3 scaled = vec3_scale(&a, 2.0);
    printf("Escala a*2: ");
    vec3_print(&scaled); // esperado: (2, 4, 6)

    // Teste vec3_minus
    vec3 neg = vec3_negate(&a);
    printf("Negativo de a: ");
    vec3_print(&neg); // esperado: (-1, -2, -3)

    // Teste vec3_div
    vec3 div = vec3_div(&a, 2.0);
    printf("Divisao a/2: ");
    vec3_print(&div); // esperado: (0.5, 1.0, 1.5)

    // Teste vec3_length e vec3_length_squared
    printf("Comprimento de a: %f\n", vec3_length(&a)); // esperado: sqrt(14)
    printf("Comprimento^2 de a: %f\n", vec3_length_squared(&a)); // esperado: 14

    // Teste vec3_dot
    printf("Produto escalar (a·b): %f\n", vec3_dot(&a, &b)); // esperado: 32

    // Teste vec3_cross
    vec3 cross = vec3_cross(&a, &b);
    printf("Produto vetorial (a x b): ");
    vec3_print(&cross); // esperado: (-3, 6, -3)

    // Teste vec3_unit_vector
    vec3 unit = vec3_unit_vector(&a);
    printf("Vetor unitario de a: ");
    vec3_print(&unit); // esperado: cada comp / sqrt(14)

    return 0;
}
