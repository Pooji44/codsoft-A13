#include <stdio.h>
#include <string.h>

// Function to get the bot's response
const char* get_bot_response(const char* user_input) {
    if (strstr(user_input, "hello") != NULL || strstr(user_input, "hi") != NULL) {
        return "Hello! How can I help you?";
    } else if (strstr(user_input, "how are you") != NULL) {
        return "I am just a simple chatbot. I don't have feelings, but thanks for asking!";
    } else if (strstr(user_input, "bye") != NULL) {
        return "Goodbye! Have a great day!";
    } else {
        return "I'm sorry, I don't understand. Can you please rephrase?";
    }
}

int main() {
    char user_input[1000];

    printf("Chatbot: Hello! How can I assist you today?\n");

    while (1) {
        printf("You: ");
        fgets(user_input, sizeof(user_input), stdin);

        // Remove the trailing newline character from the user input
        user_input[strcspn(user_input, "\n")] = '\0';

        const char* bot_response = get_bot_response(user_input);
        printf("Chatbot: %s\n", bot_response);

        // Check for the exit condition
        if (strstr(user_input, "exit") != NULL) {
            printf("Chatbot: Goodbye! See you later.\n");
            break;
        }
    }

    return 0;
}