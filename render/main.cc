// This file is published under public domain.

#include "base/command_line.h"
#include "base/strings/stringprintf.h"
#include <windows.h>
#include "third_party/imgui/src/imgui.h"
#include "third_party/imgui/src/imgui_internal.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
  base::CommandLine::Init(0, nullptr);
  ImDrawListSharedData shared_data;
  ImFontAtlas font_atlas;
  auto imgui_ctx = ImGui::CreateContext(&font_atlas);
  ImGui::SetCurrentContext(imgui_ctx);
  ImGuiIO& io = ImGui::GetIO();

  io.DisplaySize = ImVec2(800, 600);
 

  
  ImDrawList draw_list(&shared_data);
  draw_list._ResetForNewFrame();
  draw_list.AddLine(ImVec2(0, 0), ImVec2(100, 100), IM_COL32(255, 0, 0, 255), 2.0f);

  ImDrawData draw_data;
  draw_data.AddDrawList(&draw_list);
  //ImGui::DestroyContext(imgui_ctx);

  return 0;
}
