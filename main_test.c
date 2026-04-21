#include <stdio.h>
#include "html.h"
#include "csv.h"

// default parameters
char* input_filename = "table.csv";
char* output_filename = "table.html";

int main() {
    char **header = get_header(input_filename);
    int row_count = get_row_count(input_filename);
    if (header == NULL){
        return 1;
    }

    clean_html_file();
    write_html_header();

    // write table header in html
    write_html("<table>\n");
    write_html("<tr>\n");
    for (int header_index = 0; header[header_index] != NULL; header_index++) {
        print_table_header(header[header_index]);
    }
    write_html("</tr>\n");

    // write table rows in html
    for (int row_number = 1; row_number < row_count; row_number++) {
        char **row = get_row(input_filename, row_number);
        if (row == NULL || row[0] == NULL) {
            break;
        }
        write_html("<tr>\n");
        for (int column_index = 0; row[column_index] != NULL; column_index++) {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "<td>%s</td>\n", row[column_index]);
            write_html(buffer);
        }
        write_html("</tr>\n");
    }

    write_html("</table>\n");
    write_html_footer();

    printf("[i] : %d rows written to %s\n", row_count, output_filename);
    
    return 0;
}