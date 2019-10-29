#include "svarogengine.h"
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include<glad/glad.h>
#endif
SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) {
        engine_instance = new SvarogEngine;
    }
    return engine_instance;
}

void SvarogEngine::InitContext() {
    EngineWindow::getInstance()->VSYNC_on();
}


void SvarogEngine::InitMonitor() {
    svarog_monitor->init_monitor();
}

void SvarogEngine::layer_test() {
    String debug_name = String("Debug");
    ImGuiLayer* debug_layer = new ImGuiLayer(debug_name, 3);
    debug_layer->pass_frame_data(Layer_Pos::FRAME_LEFT, false, false);
    bool btn_val, btn_val2;
    debug_layer->add_button(ButtonData{String("Test_Button"), btn_val, ButtonPosition{20, 20}, 0});
    debug_layer->add_button(ButtonData{String("Test_Button2"), btn_val2, ButtonPosition{30, 30}, 1});
    ClassString* debug_class_str = debug_layer->get_layer_name();
    SvarogGuiFrame a(true, true, String("Debug_Frame"), 300, 300);
    bool is_right = (debug_class_str->get_class_id() <= 5 || debug_class_str->get_class_id() >= 0) ? true : false;
    bool is_left = (debug_class_str->get_class_id() >= 6 || debug_class_str->get_class_id() <= 10) ? true : false;
    spdlog::info("START_GUI_LAYER");
    spdlog::info("--------------------------------------------------------");
    spdlog::warn("GUI_LAYER_NAME: {}", debug_class_str->get_class_str());
    std::string pos_msg;
    if(is_right) {
        assert(debug_class_str->get_class_id() >= 0);
        switch(debug_class_str->get_class_id() - 1) {
            case 0: 
                pos_msg = "BOTTOM_RIGHT";
                break;
            case 1: 
                pos_msg = "BOTTOM_RIGHT_UP";
                break;
            case 2: 
                pos_msg = "RIGHT_MIDDLE";
                break;
            case 3: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            case 4: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            default: 
                pos_msg = "NO_POS";
                break;
        }
    }

    if(is_left) {
        assert(debug_class_str->get_class_id() >= 0);
        switch(debug_class_str->get_class_id() - 1) {
            case 0: 
                pos_msg = "BOTTOM_RIGHT";
                break;
            case 1: 
                pos_msg = "BOTTOM_RIGHT_UP";
                break;
            case 2: 
                pos_msg = "RIGHT_MIDDLE";
                break;
            case 3: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            case 4: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            default: 
                pos_msg = "NO_POS";
                break;
        }
    }
    spdlog::warn("GUI_LAYER_POS: {}", pos_msg);
    spdlog::info("--------------------------------------------------------");
    spdlog::info("END_GUI_LAYER");
    spdlog::info("-------------------------------------------------------");
    spdlog::warn("RENDERING OF GUI_TO_START");
    debug_layer->init_all();
    debug_layer->render_layer();
}

void SvarogEngine::RunEngine() {
    EngineWindow::getInstance()->SvarogAppLoop();
    InitContext();
    InitMonitor();
    //layer_test();
    String debug_name = String("Debug");
    ImGuiLayer* debug_layer = new ImGuiLayer(debug_name, 3);
    debug_layer->pass_frame_data(Layer_Pos::FRAME_LEFT, false, false);
    bool btn_val, btn_val2;
    debug_layer->add_button(ButtonData{String("Test_Button"), btn_val, ButtonPosition{200, 200}, 0});
    debug_layer->add_button(ButtonData{String("Test_Button2"), btn_val2, ButtonPosition{300, 300}, 1});
    std::function<void()>labels;
    debug_layer->add_label(LabelData{String("Label_1"), labels, LabelPosition{30, 30}, 30});
    ClassString* debug_class_str = debug_layer->get_layer_name();
    SvarogGuiFrame ca(true, true, String("Debug_Frame"), 500, 500);
    bool is_right = (debug_class_str->get_class_id() <= 5 || debug_class_str->get_class_id() >= 0) ? true : false;
    bool is_left = (debug_class_str->get_class_id() >= 6 || debug_class_str->get_class_id() <= 10) ? true : false;
    spdlog::info("START_GUI_LAYER");
    spdlog::info("--------------------------------------------------------");
    spdlog::warn("GUI_LAYER_NAME: {}", debug_class_str->get_class_str());
    std::string pos_msg;
    if(is_right) {
        assert(debug_class_str->get_class_id() >= 0);
        switch(debug_class_str->get_class_id() - 1) {
            case 0: 
                pos_msg = "BOTTOM_RIGHT";
                break;
            case 1: 
                pos_msg = "BOTTOM_RIGHT_UP";
                break;
            case 2: 
                pos_msg = "RIGHT_MIDDLE";
                break;
            case 3: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            case 4: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            default: 
                pos_msg = "NO_POS";
                break;
        }
    }

    if(is_left) {
        assert(debug_class_str->get_class_id() >= 0);
        switch(debug_class_str->get_class_id() - 1) {
            case 0: 
                pos_msg = "BOTTOM_RIGHT";
                break;
            case 1: 
                pos_msg = "BOTTOM_RIGHT_UP";
                break;
            case 2: 
                pos_msg = "RIGHT_MIDDLE";
                break;
            case 3: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            case 4: 
                pos_msg = "TOP_RIGHT_DOWN";
                break;
            default: 
                pos_msg = "NO_POS";
                break;
        }
    }
    spdlog::warn("GUI_LAYER_POS: {}", pos_msg);
    spdlog::info("--------------------------------------------------------");
    spdlog::info("END_GUI_LAYER");
    spdlog::info("-------------------------------------------------------");
    spdlog::warn("RENDERING OF GUI_TO_START");
    debug_layer->init_all();
    std::string vert_shader, frag_shader;
    std::ifstream vert, frag;
    vert.exceptions(std::ifstream::failbit);
    frag.exceptions(std::ifstream::failbit);
    try {
        vert.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainvertex_shader.glsl");
        frag.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainfragment_shader.glsl");
        std::stringstream aa, aba;
        aa << vert.rdbuf();
        aba << frag.rdbuf();
        vert.close();
        frag.close();
        vert_shader = aa.str();
        frag_shader = aba.str();
    } catch (ifstream::failure e) {
        std::cout << e.what() << '\n';
    }
    const char* vert_s = vert_shader.c_str();
    const char* frag_s = frag_shader.c_str();
    VertexShader vert_m;
    vert_m.set_code(vert_s);
    vert_m.set_use_state();
    vert_m.compile_shader();
    FragmentShader frag_m; 
    frag_m.set_code(frag_s);
    frag_m.set_use_state();
    frag_m.compile_shader();
    ShaderProgram * test_prg = new ShaderProgram();
    test_prg->bind_shaders(vert_m, frag_m);
    //SvarogMaterial debug_mat;
    //debug_mat.is_assigned_to_mesh();
    //debug_mat.set_material_name("frag_color");
    //debug_mat.set_rgb(Rgb(1.0, 0.5, 1.0));
    //debug_mat.set_primary_color_model(COLOR_MODEL::RGB_MODEL);
    //ShaderGeneration::generateShaderCode()->input_mat(debug_mat);
    //ShaderGeneration::generateShaderCode()->make_shaders();
    //ShaderGeneration::generateShaderCode()->send_shaders();

    float vertices[] = {
        0.5f,  0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f , -0.5f, 
        0.5f, -0.5f , 0.5f, 
        0.5f, 0.5f , 0.5f, 
    };        
    
    unsigned int poss[] = {  
        0, 1, 3,  
        1, 2, 3,
        0, 1, 2,
    };

    SvarogShape mesh_tst;
    std::vector<float>vertt;
    std::vector<unsigned int>pos;

    for(int i = 0; i < 18; i++) {
        vertt.push_back(vertices[i]);
    }
    for(int j = 0; j < 9; j++) {
        pos.push_back(poss[j]);
    }
    mesh_tst.pass_position_data(pos);
    mesh_tst.pass_vert_data(vertt);
    mesh_tst.init();
    // renderable obj debug.
    RenderObj* s = new RenderObj();
    s->set_mesh_id(1);
    s->set_mesh_name(String("Debug_Mesh"));
    s->input_mesh(mesh_tst);
    // debug im gui context
    ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow()), "#version 400");
    ImGuiInit::make_imgui_style(0);
    
    SvarogGuiFrame * test = new SvarogGuiFrame(true, true, "Shaders", 500, 500);
    
    char* debug = new char[3];
    debug[0] = 'e';
    debug[1] = 'd';
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        test_prg->use();
        ImGuiInit::init_imgui_frames();
        test->begin_gui_frame();
        {
            ImGui::SetCursorPos(ImVec2(10, 10));
            SvarogButton dbg_btn(100, 60, "Debug_Button", true);
            SvarogInputText ad("Steve", debug ,3);
            static float size_m = 0.0f;
            ImGui::SliderFloat("Debug_Slider", &size_m, 0.0f, 1.0f);
        }
        test->end_gui_frame();
        ca.begin_gui_frame();
        {
            debug_layer->render_layer();
        }
        ca.end_gui_frame();
        s->get_mesh().draw();
        ImGuiInit::init_imgui_render();
        EngineWindow::getInstance()->OnUpdate();
    }
    s->get_mesh().del_buffers();
    ImGuiInit::init_imgui_shutdown();
}
SvarogEngine* SvarogEngine::engine_instance = 0;
