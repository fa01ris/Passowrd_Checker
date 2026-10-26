#include <stdio.h>
#include <string.h>

int main(void) {
    char password[100];
    int length;
    int valid;   

    start_again:

    printf("Enter your password: ");
    scanf("%99s", password);

    length = strlen(password);

    // الشرط الذي يتحقق من كلمة المرور انها لا تقل عن 8 خانات
    if (length < 9) {
        printf("- Error: The Password must be more than 8 characters.\n");
        valid = 0;
    }

    // الشرط الذي يتحقق من كلمة المرور انها ضروري تحتوي على أحرف صغيرة
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") == NULL) {
        printf("- Error: The Password Must have a lowercase letter.\n");
        valid = 0;
    }

    // الشرط الذي يتحقق من كلمة المرور انها ضروري تحتوي على أحرف كبيرة
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == NULL) {
        printf("- Error: The Password Must have an uppercase letter.\n");
        valid = 0;
    }

    // الشرط الذي يتحقق من كلمة المرور انها ضروري تحتوي على أرقام
    if (strpbrk(password, "0123456789") == NULL) {
        printf("- Error: The Password Must have a number.\n");
        valid = 0;
    }

    // الشرط الذي يتحقق من كلمة المرور انها ضروري تحتوي على رموز
    if (strpbrk(password, "!@#$%^&*()_+-=[]{}|;':\",./<>?") == NULL) {
        printf("- Error: The Password Must have a symbol.\n");
        valid = 0;
    }

    // الشرط الذي يتحقق من كلمة المرور انها لا تحتوي على أحرف من لغة اخرى غير الانجليزي    if (strspn(password,
    if (strspn(password, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\",./<>?") != length) {
        printf("- Error: Only English letters, numbers and symbols allowed.\n");
        valid = 0;
    }

    if (valid == 1) {
        printf("\nPassword accepted successfully!\n");
    }

    if (valid == 0) {
        printf("\nPassword rejected. Please try again.\n");
        
        goto start_again; // اذا كانت كلمة المرو خاطئة يتم إرجاع المتسخدم للمحاولة مرة
    }

    return 0;
}