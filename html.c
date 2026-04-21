#include <stdio.h>

char* html_filename = "table.html";

void write_html(char* content) {
    FILE* file = fopen(html_filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

void clean_html_file() {
    FILE* file = fopen(html_filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fclose(file);
}

void write_html_header() {
    write_html("<!DOCTYPE html>\n");
    write_html("<html lang=\"en\">\n");
    write_html("<head>\n");
    write_html("    <meta charset=\"UTF-8\">\n");
    write_html("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    write_html("    <title>Document</title>\n");
    write_html("    <link rel=\"stylesheet\" type=\"text/css\" href=\"table.css\">\n");
    write_html("</head>\n");
    write_html("<body>\n");
    write_html("<h1>CSV to HTML Table : INT student list with github</h1>\n");
}

void write_footer() {
    write_html("</body>\n");
    write_html("</html>\n");
}

void write_html_footer() {
    write_html("</body>\n");
    write_html("</html>\n");
}

void initiate_table_header(char* header) {
    char buffer[256];
    write_html("<table>\n");
    snprintf(buffer, sizeof(buffer), "<th>%s</th>\n", header);
    write_html(buffer);
}

void print_table_header(char* header){
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "<th>%s</th>\n", header);
    write_html(buffer);
}
