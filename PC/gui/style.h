#pragma once

#include "vendor/imgui/imgui.h"

namespace GUI {

struct ThemeColors {
  bool isDark;
  ImVec4 bg;
  ImVec4 surface;
  ImVec4 card;
  ImVec4 cardBorder;
  ImVec4 accent;
  ImVec4 accentDark;
  ImVec4 accentGlow;
  ImVec4 terminalGreen;
  ImVec4 terminalYellow;
  ImVec4 textPrimary;
  ImVec4 textSecondary;
  ImVec4 textMuted;
  ImVec4 btnText;
};

inline ThemeColors g_currentTheme;

inline const ThemeColors &getTheme() {
  return g_currentTheme;
}

inline void applyTheme(bool darkMode) {
  g_currentTheme.isDark = darkMode;

  if (darkMode) {
    // Dark mode com fundo profundo e acentos azuis
    g_currentTheme.bg             = ImVec4(0.039f, 0.051f, 0.078f, 1.00f); // #0A0D14
    g_currentTheme.surface        = ImVec4(0.063f, 0.082f, 0.122f, 1.00f); // #10151F
    g_currentTheme.card           = ImVec4(0.086f, 0.110f, 0.161f, 1.00f); // #161C29
    g_currentTheme.cardBorder     = ImVec4(0.145f, 0.188f, 0.275f, 1.00f); // #253046
    g_currentTheme.accent         = ImVec4(0.231f, 0.510f, 0.965f, 1.00f); // #3B82F6
    g_currentTheme.accentDark     = ImVec4(0.145f, 0.388f, 0.922f, 1.00f); // #2563EB
    g_currentTheme.accentGlow     = ImVec4(0.376f, 0.647f, 0.980f, 1.00f); // #60A5FA
    g_currentTheme.terminalGreen  = ImVec4(0.000f, 0.902f, 0.463f, 1.00f); // #00E676
    g_currentTheme.terminalYellow = ImVec4(1.000f, 0.839f, 0.000f, 1.00f); // #FFD600
    g_currentTheme.textPrimary    = ImVec4(0.945f, 0.965f, 0.988f, 1.00f); // #F1F6FC
    g_currentTheme.textSecondary  = ImVec4(0.580f, 0.639f, 0.722f, 1.00f); // #94A3B8
    g_currentTheme.textMuted      = ImVec4(0.392f, 0.455f, 0.545f, 1.00f); // #64748B
    g_currentTheme.btnText        = ImVec4(1.000f, 1.000f, 1.000f, 1.00f); // #FFFFFF
  } else {
    // Light mode limpo com azul Perseus
    g_currentTheme.bg             = ImVec4(0.961f, 0.973f, 0.988f, 1.00f); // #F5F8FC
    g_currentTheme.surface        = ImVec4(1.000f, 1.000f, 1.000f, 1.00f); // #FFFFFF
    g_currentTheme.card           = ImVec4(0.929f, 0.949f, 0.976f, 1.00f); // #EDF2F9
    g_currentTheme.cardBorder     = ImVec4(0.812f, 0.863f, 0.929f, 1.00f); // #CFDCEC
    g_currentTheme.accent         = ImVec4(0.145f, 0.388f, 0.922f, 1.00f); // #2563EB
    g_currentTheme.accentDark     = ImVec4(0.114f, 0.306f, 0.847f, 1.00f); // #1D4ED8
    g_currentTheme.accentGlow     = ImVec4(0.231f, 0.510f, 0.965f, 1.00f); // #3B82F6
    g_currentTheme.terminalGreen  = ImVec4(0.000f, 0.800f, 0.400f, 1.00f);
    g_currentTheme.terminalYellow = ImVec4(0.850f, 0.680f, 0.000f, 1.00f);
    g_currentTheme.textPrimary    = ImVec4(0.059f, 0.090f, 0.165f, 1.00f); // #0F172A
    g_currentTheme.textSecondary  = ImVec4(0.278f, 0.333f, 0.412f, 1.00f); // #475569
    g_currentTheme.textMuted      = ImVec4(0.580f, 0.639f, 0.722f, 1.00f); // #94A3B8
    g_currentTheme.btnText        = ImVec4(1.000f, 1.000f, 1.000f, 1.00f);
  }

  ImGuiStyle &style = ImGui::GetStyle();
  ImVec4 *colors = style.Colors;

  style.WindowRounding    = 12.0f;
  style.ChildRounding     = 10.0f;
  style.FrameRounding     = 8.0f;
  style.PopupRounding     = 10.0f;
  style.ScrollbarRounding = 8.0f;
  style.GrabRounding      = 8.0f;
  style.TabRounding       = 8.0f;

  style.WindowBorderSize  = 1.0f;
  style.ChildBorderSize   = 1.0f;
  style.FrameBorderSize   = 0.0f;
  style.PopupBorderSize   = 1.0f;

  style.WindowPadding     = ImVec2(18.0f, 16.0f);
  style.FramePadding      = ImVec2(12.0f, 9.0f);
  style.ItemSpacing       = ImVec2(12.0f, 10.0f);
  style.ItemInnerSpacing  = ImVec2(8.0f, 6.0f);
  style.ScrollbarSize     = 12.0f;

  colors[ImGuiCol_Text]                  = g_currentTheme.textPrimary;
  colors[ImGuiCol_TextDisabled]          = g_currentTheme.textMuted;
  colors[ImGuiCol_WindowBg]              = g_currentTheme.bg;
  colors[ImGuiCol_ChildBg]               = g_currentTheme.card;
  colors[ImGuiCol_PopupBg]               = g_currentTheme.surface;
  colors[ImGuiCol_Border]                = g_currentTheme.cardBorder;
  colors[ImGuiCol_BorderShadow]          = ImVec4(0, 0, 0, 0);

  colors[ImGuiCol_FrameBg]               = g_currentTheme.surface;
  colors[ImGuiCol_FrameBgHovered]        = g_currentTheme.cardBorder;
  colors[ImGuiCol_FrameBgActive]         = g_currentTheme.cardBorder;

  colors[ImGuiCol_TitleBg]               = g_currentTheme.bg;
  colors[ImGuiCol_TitleBgActive]         = g_currentTheme.bg;
  colors[ImGuiCol_TitleBgCollapsed]      = g_currentTheme.bg;

  colors[ImGuiCol_MenuBarBg]             = g_currentTheme.card;
  colors[ImGuiCol_ScrollbarBg]           = g_currentTheme.bg;
  colors[ImGuiCol_ScrollbarGrab]         = g_currentTheme.cardBorder;
  colors[ImGuiCol_ScrollbarGrabHovered]  = g_currentTheme.textSecondary;
  colors[ImGuiCol_ScrollbarGrabActive]   = g_currentTheme.accent;

  colors[ImGuiCol_CheckMark]             = g_currentTheme.accent;
  colors[ImGuiCol_SliderGrab]            = g_currentTheme.accent;
  colors[ImGuiCol_SliderGrabActive]      = g_currentTheme.accentGlow;

  colors[ImGuiCol_Button]                = g_currentTheme.accent;
  colors[ImGuiCol_ButtonHovered]         = g_currentTheme.accentGlow;
  colors[ImGuiCol_ButtonActive]          = g_currentTheme.accentDark;

  colors[ImGuiCol_Header]                = g_currentTheme.card;
  colors[ImGuiCol_HeaderHovered]         = g_currentTheme.cardBorder;
  colors[ImGuiCol_HeaderActive]          = g_currentTheme.accent;

  colors[ImGuiCol_Separator]             = g_currentTheme.cardBorder;
  colors[ImGuiCol_SeparatorHovered]      = g_currentTheme.accent;
  colors[ImGuiCol_SeparatorActive]       = g_currentTheme.accentGlow;

  colors[ImGuiCol_ResizeGrip]            = ImVec4(0, 0, 0, 0);
  colors[ImGuiCol_ResizeGripHovered]     = g_currentTheme.cardBorder;
  colors[ImGuiCol_ResizeGripActive]      = g_currentTheme.accent;

  colors[ImGuiCol_Tab]                   = g_currentTheme.card;
  colors[ImGuiCol_TabHovered]            = g_currentTheme.accentGlow;
  colors[ImGuiCol_TabActive]             = g_currentTheme.accent;
  colors[ImGuiCol_TabUnfocused]          = g_currentTheme.card;
  colors[ImGuiCol_TabUnfocusedActive]    = g_currentTheme.cardBorder;
}

} // namespace GUI
