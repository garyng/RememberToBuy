# ImGui Notes

## Helper Tootlip

```cpp
static void ShowHelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
```

## Bullets

```cpp
ImGui::BulletText("lorem");
ImGui::Indent();

ImGui::BulletText("lorem");

ImGui::Unindent();
```

## Begin, End

```cpp
// - Passing 'bool* p_open' displays a Close button on the upper-right corner of the window, the pointed value will be set to false when the button is pressed.
if (!ImGui::Begin("ImGui Demo", p_open, window_flags))
{
    // Early out if the window is collapsed, as an optimization.
    ImGui::End();
    return;
}
``
`
## Menu

```cpp
if (ImGui::BeginMenuBar())
{
    if (ImGui::BeginMenu("Menu"))
    {
        ShowExampleMenuFile();
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Examples"))
    {
        // ...
        ImGui::MenuItem("Custom rendering", NULL, &show_app_custom_rendering);
        ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
}
```

## Tree

```cpp
if (ImGui::CollapsingHeader("Help"))
{
    ImGui::TextWrapped("This window is being created by the ShowDemoWindow() function. Please refer to the code in imgui_demo.cpp for reference.\n\n");
    ImGui::Text("USER GUIDE:");
    ImGui::ShowUserGuide();
}
```

```cpp
if (ImGui::CollapsingHeader("Window options"))
{
    // ...
    ImGui::Checkbox("No nav", &no_nav);

    if (ImGui::TreeNode("Style"))
    {
        ImGui::ShowStyleEditor();
        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Capture/Logging"))
    {
        // ...
        ImGui::TreePop();
    }
}
```

## Spacing

```cpp
ImGui::Spacing();
```

## Sameline

```cpp

ImGui::Checkbox("No titlebar", &no_titlebar); ImGui::SameLine(150);
ImGui::Checkbox("No scrollbar", &no_scrollbar); ImGui::SameLine(300);
ImGui::Checkbox("No menu", &no_menu);

// Gets back to previous line and continue with horizontal layout
//      pos_x == 0      : follow right after previous item
//      pos_x != 0      : align to specified x position (relative to window/group left)
//      spacing_w < 0   : use default spacing if pos_x == 0, no spacing if pos_x != 0
//      spacing_w >= 0  : enforce spacing amount
void ImGui::SameLine(float pos_x, float spacing_w)
```

## Buttons

```cpp
if (ImGui::Button("Button"))
    clicked++;
if (clicked & 1)
{
    ImGui::SameLine();
    ImGui::Text("Thanks for clicking me!");
}
```

## Checkbox
```cpp
ImGui::Checkbox("checkbox", &check);
```

## Radio button

```cpp
static int e = 0;
ImGui::RadioButton("radio a", &e, 0); ImGui::SameLine();
ImGui::RadioButton("radio b", &e, 1); ImGui::SameLine();
ImGui::RadioButton("radio c", &e, 2);
```


## Push/Pop Styles
```cpp
ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i/7.0f, 0.6f, 0.6f));
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i/7.0f, 0.7f, 0.7f));
ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i/7.0f, 0.8f, 0.8f));
ImGui::Button("Click");
ImGui::PopStyleColor(3);
```




























## VS Project

```xml
      <AdditionalIncludeDirectories>$(ProjectDir);$(SolutionDir)\..\libs\poco\include\Data;$(SolutionDir)\..\libs\poco\include\Foundation;$(SolutionDir)\..\libs\date;$(SolutionDir)\..\libs\PicoSHA2;$(SolutionDir)\..\libs\linq;$(SolutionDir)\..\libs\json;$(SolutionDir)\..\libs\better-enums;$(SolutionDir)\..\libs\IconFontCppHeaders;$(SolutionDir)\..\libs\gl3w\;$(SolutionDir)\..\libs\glfw\include\;$(SolutionDir)\..\libs\imgui;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>


      <LanguageStandard>stdcpplatest</LanguageStandard>


      <RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary>


      <AdditionalLibraryDirectories>$(SolutionDir)\..\libs\poco\lib;$(SolutionDir)\..\libs\glfw\lib-vc2017;%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>

      <AdditionalDependencies>opengl32.lib;glfw3.lib;ws2_32.lib;iphlpapi.lib;%(AdditionalDependencies)</AdditionalDependencies>

      <Command>XCOPY "$(SolutionDir)fonts" "$(SolutionDir)..\bin\fonts\" /s /i /y /d
XCOPY "$(TargetDir)$(TargetName)$(TargetExt)" "$(SolutionDir)..\bin\" /s /i /y /d</Command>


<ClCompile Include="..\libs\gl3w\GL\gl3w.c">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">NotUsing</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">NotUsing</PrecompiledHeader>
    </ClCompile>
    <ClCompile Include="..\libs\imgui\addons\imguidatechooser\imguidatechooser.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">NotUsing</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">NotUsing</PrecompiledHeader>
    </ClCompile>
    <ClCompile Include="..\libs\imgui\imgui.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">NotUsing</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">NotUsing</PrecompiledHeader>
    </ClCompile>
    <ClCompile Include="..\libs\imgui\imgui_custom.cpp" />
    <ClCompile Include="..\libs\imgui\imgui_demo.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">NotUsing</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">NotUsing</PrecompiledHeader>
    </ClCompile>
    <ClCompile Include="..\libs\imgui\imgui_draw.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">NotUsing</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">NotUsing</PrecompiledHeader>
    </ClCompile>
    <ClCompile Include="..\libs\imgui\imgui_impl_glfw_gl3.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">NotUsing</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">NotUsing</PrecompiledHeader>
    </ClCompile>



    <ClCompile Include="stdafx.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">Create</PrecompiledHeader>
    </ClCompile>
```