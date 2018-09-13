#pragma once

#include "stdbool.h"
#include "nuklear.h"
#include "nuklear_glfw_gl3.h"
#include "overview.h"


void nuklear_draw(struct nk_context* out_ctx, const int in_width, const int in_height){

    /* Global variables of the app */
    bool main_menu_hovered = false;

    /* Global variables to change the style of the components */
    struct nk_style* s = &out_ctx->style; 
    struct nk_style_item style_item;
    struct nk_vec2 vec2_item;
    struct nk_color color_item;

    /********************************* Window main_menu top bar ******************************/
        /***************************** Push style menu_button ***************************/
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

        /***************************** Push style buttons *******************************/
            // Change the hover color of buttons
            style_item = nk_style_item_color(nk_rgba(70, 70, 70, 200));
            nk_style_push_style_item(out_ctx, &s->button.hover, style_item);

            // Change the border color of the buttons
            color_item = nk_rgba(15, 15, 15, 255);
            nk_style_push_color(out_ctx, &s->button.border_color, color_item);

            // Change the form of the buttons
            nk_style_push_float(out_ctx, &s->button.rounding, 0.0f);
        /********************************************************************************/
    
        /***************************** Push style window ********************************/
            // Change the background color of the window
            style_item = nk_style_item_color(nk_rgba(39, 43, 51, 255));
            nk_style_push_style_item(out_ctx, &s->window.fixed_background, style_item);
            
            // Change the padding of the window
            vec2_item = nk_vec2(1, 2);
            nk_style_push_vec2(out_ctx, &s->window.padding, vec2_item);

            // Change the border color of the window
            color_item = nk_rgba(15, 15, 15, 255);
            nk_style_push_color(out_ctx, &s->window.border_color, color_item);

            // Change the tickness of the border of the window
            nk_style_push_float(out_ctx, &s->window.border, 1.0f);
        /********************************************************************************/
    
        /***************************** Draw main_menu window ****************************/
            nk_begin(out_ctx, "main_menu", nk_rect(0, 0, (float)in_width, 25), NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_BORDER); 
                    typedef enum ACTIVE_MENU{
                        MAIN_MENU,
                        HELP
                    } ACTIVE_MENU;
                    if(nk_window_is_hovered(out_ctx)){
                        main_menu_hovered = true;
                    }
                    nk_menubar_begin(out_ctx);
                        nk_layout_row_begin(out_ctx, NK_STATIC, 18, 4);
                        // Menu button
                        nk_layout_row_push(out_ctx, 35);
                        if(nk_widget_is_hovered(out_ctx)){
                            printf(" hover Menu ");
                        }
                        if(nk_menu_begin_label(out_ctx, "Menu", NK_TEXT_LEFT, nk_vec2(300, 500))){
                            nk_layout_row_dynamic(out_ctx, 500, 2);
                            if(nk_widget_is_hovered(out_ctx)){
                                printf(" test ");
                            }
                            nk_menu_end(out_ctx);
                        }
                        // Edit button
                        nk_layout_row_push(out_ctx, 40);
                        if(nk_widget_is_hovered(out_ctx)){
                            printf(" hover Edit ");
                        }
                        if(nk_menu_begin_label(out_ctx, "Edit", NK_TEXT_LEFT, nk_vec2(300, 500))){
                            nk_layout_row_dynamic(out_ctx, 500, 2);
                            nk_menu_end(out_ctx);
                        }
                        // Help button
                        nk_layout_row_push(out_ctx, 35);
                        if(nk_widget_is_hovered(out_ctx)){
                            printf(" hover Help ");
                        }
                        if (nk_menu_begin_label(out_ctx, "Help", NK_TEXT_LEFT, nk_vec2(120, 200))){
                            static size_t prog = 40;
                            static int slider = 10;
                            static int check = nk_true;
                            nk_layout_row_dynamic(out_ctx, 25, 1);
                            nk_progress(out_ctx, &prog, 100, NK_MODIFIABLE);
                            nk_slider_int(out_ctx, 0, &slider, 16, 1);
                            nk_checkbox_label(out_ctx, "check", &check);
                            nk_menu_end(out_ctx);
                        }
                    nk_menubar_end(out_ctx);
            nk_end(out_ctx);
        /********************************************************************************/

        /***************************** Pop style menu_buttons ***************************/
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_color(out_ctx);
            nk_style_pop_float(out_ctx);
        /********************************************************************************/

        /***************************** Pop style buttons ********************************/
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_color(out_ctx);
            nk_style_pop_float(out_ctx);
        /********************************************************************************/
    
        /***************************** Pop style window *********************************/
            nk_style_pop_style_item(out_ctx);
            nk_style_pop_vec2(out_ctx);
            nk_style_pop_color(out_ctx);
            nk_style_pop_float(out_ctx);
        /********************************************************************************/
    /*****************************************************************************************/

    // /********************************* Window menu_left **************************************/
        
    //     nk_begin(out_ctx, "menu_left", nk_rect(0, 25, 200, in_height), NK_WINDOW_BORDER);
    //         if(nk_window_is_hovered(out_ctx)){
    //             menu_left_hovered = true;
    //         }
    //         nk_layout_row_begin(out_ctx, NK_STATIC, 50, 1);
    //         nk_layout_row_dynamic(out_ctx, 20, 1);
    //         static int check = nk_true;
    //         nk_checkbox_label(out_ctx, "check", &check);
    //     nk_end(out_ctx);

    // /*****************************************************************************************/

    overview(out_ctx);

    /******************************** Handle events *****************************************/
        /* Change focus to main_menu if it is hovered */
        if(main_menu_hovered)
            nk_window_set_focus(out_ctx, "main_menu");
 
    /****************************************************************************************/
}