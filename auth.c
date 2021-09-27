#include <stdio.h>
#include <string.h>

int authenticate(){

  /* Using a struct for the local variables forces them */
  /* to be created in a particular order on the stack.  */
  /* Otherwise, the compiler is free to create them in  */
  /* any order it likes.                                */
  struct {
    char password[7];
    char  auth;
  } locals;

  /* Until the user authenticates, set the auth flag to */
  /* FALSE.  (In C, 0 == FALSE, and any nonzero value   */
  /* equates to TRUE.)                                  */
  locals.auth = 0;

  /* Prompt the user for their password and store it */
  printf("Please enter your password:");
  gets(locals.password);

  /* Compare the password entered to the true password.   */
  /* If they match, set the auth flag to TRUE.            */
  if (!strcmp("secret", locals.password)) {
    locals.auth = 1;
  }

  /* Return the auth flag (0 or 1) to the caller. */
  return locals.auth;
}


int main(){

  /* Check if the user correctly authenticated */
  if (authenticate()) {

    /* If so, print an appropriate message. */
    printf("User authenticated.\n");

  /* Otherwise, let them know. */
  } else {
    printf("INCORRECT!\n");
  }

}