#pragma once

#include "nuklear.h"
#include "nuklear_glfw_gl3.h"

void nuklear_set_settings(GLFWwindow *in_win, struct nk_context *out_out_ctx){
    /* Load Fonts: if none of these are loaded a default font will be used  */
    /* Load Cursor: if you uncomment cursor loading please hide the cursor */
    {
        /*struct nk_font *droid = nk_font_atlas_add_from_file(atlas, "../../../extra_font/DroidSans.ttf", 14, 0);*/
        /*struct nk_font *roboto = nk_font_atlas_add_from_file(atlas, "../../../extra_font/Roboto-Regular.ttf", 14, 0);*/
        /*struct nk_font *future = nk_font_atlas_add_from_file(atlas, "../../../extra_font/kenvector_future_thin.ttf", 13, 0);*/
        /*struct nk_font *clean = nk_font_atlas_add_from_file(atlas, "../../../extra_font/ProggyClean.ttf", 12, 0);*/
        /*struct nk_font *tiny = nk_font_atlas_add_from_file(atlas, "../../../extra_font/ProggyTiny.ttf", 10, 0);*/
        /*struct nk_font *cousine = nk_font_atlas_add_from_file(atlas, "../../../extra_font/Cousine-Regular.ttf", 13, 0);*/

        // nk_style_load_all_cursors(out_ctx, atlas->cursors);
        // nk_style_set_font(out_ctx, &droid->handle); 
    }

    #ifdef INCLUDE_STYLE
    /*set_style(out_ctx, THEME_WHITE);*/
    /*set_style(out_ctx, THEME_RED);*/
        // set_style(out_out_ctx, THEME_BLUE);
        //set_style(out_ctx, THEME_DARK);
    #endif
}




void nuklear_draw(struct nk_context* out_ctx, const int in_width, const int in_height){
    static int show_menu = nk_true;

    /* Main menu on top of the window */
    {
        struct nk_style* s = &out_ctx->style; 
        struct nk_style_item style_item;
        struct nk_vec2 vec2_item;
        
        // Change the main bar color on top
        style_item = nk_style_item_color(nk_rgba(40, 40, 40, 255));
        nk_style_push_style_item(out_ctx, &s->window.fixed_background, style_item);
        
        // Change the padding of the default window to have 0 border on top
        vec2_item = nk_vec2(0, 0);
        nk_style_push_vec2(out_ctx, &s->window.padding, vec2_item);

        // Change the hover color for button
        style_item = nk_style_item_color(nk_rgba(60, 60, 60, 200));
        nk_style_push_style_item(out_ctx, &s->menu_button.hover, style_item);

        // Change the color of buttons
        style_item = nk_style_item_color(nk_rgba(25, 25, 25, 255));
        nk_style_push_style_item(out_ctx, &s->menu_button.normal, style_item);

        nk_begin(out_ctx, "Menu", nk_rect(0, 0, (float)in_width, 20), NK_WINDOW_NO_INPUT | NK_WINDOW_NO_SCROLLBAR);
            /* menu #1 */
                nk_layout_row_begin(out_ctx, NK_STATIC, 20, 1);
                nk_layout_row_push(out_ctx, 35);
                if (nk_menu_begin_label(out_ctx, "MENU", NK_TEXT_LEFT, nk_vec2(200, 200))){
                    static size_t prog = 40;
                    static int slider = 10;
                    static int check = nk_true;
                    nk_layout_row_dynamic(out_ctx, 25, 1);
                    // if (nk_menu_item_label(out_ctx, "Hide", NK_TEXT_LEFT))
                    //     show_menu = nk_false;
                    nk_progress(out_ctx, &prog, 100, NK_MODIFIABLE);
                    nk_slider_int(out_ctx, 0, &slider, 16, 1);
                    nk_checkbox_label(out_ctx, "check", &check);
                    nk_menu_end(out_ctx);
                }
        nk_end(out_ctx);
        nk_style_pop_style_item(out_ctx);
        nk_style_pop_vec2(out_ctx);
        nk_style_pop_style_item(out_ctx);
        nk_style_pop_style_item(out_ctx);
    }

}