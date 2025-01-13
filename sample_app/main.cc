// This file is published under public domain.

#include "base/command_line.h"
#include "nativeui/nativeui.h"
#include "base/strings/stringprintf.h"

#if defined(OS_WIN)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
  base::CommandLine::Init(0, nullptr);
#else
int main(int argc, const char *argv[]) {
  base::CommandLine::Init(argc, argv);
#endif

  // Intialize GUI toolkit.
  nu::Lifetime lifetime;

  // Initialize the global instance of nativeui.
  nu::State state;

  // Create window with default options, and then show it.
  scoped_refptr<nu::Window> window(new nu::Window(nu::Window::Options()));
  auto button = new nu::Button("Hello world");
  int a = 0;
  button->on_click.Connect([&](nu::Button* button) {
      button->SetTitle(base::StringPrintf("Hello world %d",++a));
      });
  window->SetContentView(button);
  window->SetContentSize(nu::SizeF(400, 400));
  window->Center();
  window->Activate();

  // Quit when window is closed.
  window->on_close.Connect([](nu::Window*) {
    nu::MessageLoop::Quit();
  });

  // Enter message loop.
  nu::MessageLoop::Run();

  return 0;
}
