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

    /* Main menu on top of the window */
    {
        struct nk_style* s = &out_ctx->style; 
        struct nk_style_item style_item;
        struct nk_vec2 vec2_item;
        struct nk_color color_item;

        /****************************** Style menu_buttons *******************************/
            // Change the hover color of menu_buttons
            style_item = nk_style_item_color(nk_rgba(70, 70, 70, 200));
            nk_style_push_style_item(out_ctx, &s->menu_button.hover, style_item);
            
            // Change the color of menu_buttons
            style_item = nk_style_item_color(nk_rgba(30, 30, 30, 255));
            nk_style_push_style_item(out_ctx, &s->menu_button.normal, style_item);

            // Change the border color of the menu_buttons
            color_item = nk_rgba(15, 15, 15, 255);
            nk_style_push_color(out_ctx, &s->menu_button.border_color, color_item);

            // Change the border size the menu_buttons
            nk_style_push_float(out_ctx, &s->menu_button.border, 0.8f);
        /********************************************************************************/

        /******************************** Style buttons *********************************/
            // Change the hover color of buttons
            style_item = nk_style_item_color(nk_rgba(70, 70, 70, 200));
            nk_style_push_style_item(out_ctx, &s->button.hover, style_item);

            // Change the border color of the buttons
            color_item = nk_rgba(15, 15, 15, 255);
            nk_style_push_color(out_ctx, &s->button.border_color, color_item);

            // Change the form of the buttons
            nk_style_push_float(out_ctx, &s->button.rounding, 0.0f);
        /********************************************************************************/
        
        /********************************* Style window *********************************/
            // Change the background color of the window
            style_item = nk_style_item_color(nk_rgba(39, 43, 51, 255));
            nk_style_push_style_item(out_ctx, &s->window.fixed_background, style_item);
            
            // Change the padding of the window
            vec2_item = nk_vec2(1, 2);
            nk_style_push_vec2(out_ctx, &s->window.padding, vec2_item);

            // Change the border color of the window
            color_item = nk_rgba(15, 15, 15, 255);
            nk_style_push_color(out_ctx, &s->window.border_color, color_item);
        /********************************************************************************/
        

        nk_begin(out_ctx, "menu", nk_rect(0, 0, (float)in_width, 25), NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_BORDER_BOTTOM); 
                nk_layout_row_begin(out_ctx, NK_STATIC, 18, 2);
                    if(nk_window_is_hovered(out_ctx)){
                        printf(nk_window_has_focus(out_ctx, "menu") ? "ok" : "ko");
                    }
                    nk_layout_row_push(out_ctx, 35);
                    if (nk_menu_begin_label(out_ctx, "Menu", NK_TEXT_LEFT, nk_vec2(300, 500))){
                        static int check = nk_true;
                        nk_layout_row_dynamic(out_ctx, 20, 1);
                        nk_checkbox_label(out_ctx, "check", &check);
                        nk_menu_end(out_ctx);
                    }
                nk_layout_row_push(out_ctx, 40);
                if(nk_button_label(out_ctx, "Help")){

                }
        nk_end(out_ctx);

        /****************************** Style menu_buttons *******************************/
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_color(out_ctx);
            nk_style_pop_float(out_ctx);
        /********************************************************************************/

        /******************************** Style buttons *********************************/
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_color(out_ctx);
            nk_style_pop_float(out_ctx);
        /********************************************************************************/
        
        /********************************* Style window *********************************/
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_vec2(out_ctx);
            nk_style_pop_color(out_ctx);
        /********************************************************************************/
        
        
    }

    /* Menu left */
    {
        nk_begin(out_ctx, "menu_left", nk_rect(0, 25, 200, in_height), NK_WINDOW_BORDER); 
                nk_layout_row_begin(out_ctx, NK_STATIC, 50, 1);
                nk_layout_row_dynamic(out_ctx, 20, 1);
                static int check = nk_true;
                nk_checkbox_label(out_ctx, "check", &check);
        nk_end(out_ctx);
    }

}