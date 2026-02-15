/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:00:34 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/15 11:10:21 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

    #include "svc.h"

	#include <stdio.h>

#pragma endregion

#pragma region "Variables"

	char g_WinkeyPath[MAX_PATH];

#pragma endregion

#pragma region "Winkey Path"

	void WinkeyPath(char *Path) {
		char *lastSlash;

		if (!GetModuleFileName(NULL, Path, MAX_PATH) || !(lastSlash = strrchr(Path, '\\'))) return;
		strcpy_s(lastSlash + 1, Path + MAX_PATH - (lastSlash + 1), "winkey.exe");
	}

#pragma endregion

#pragma region "Main"

	int main(int argc, char **argv) {
		// Set Winkey.exe fullpath
		WinkeyPath(g_WinkeyPath);

		// Executed as a service
		if (StartServiceCtrlDispatcher((SERVICE_TABLE_ENTRY[]) {{ Name, (LPSERVICE_MAIN_FUNCTION)ServiceMain }, { NULL, NULL }})) return (0);

		DWORD dwSize;
		HANDLE hToken;
		TOKEN_ELEVATION elevation = {0};

		// Open token
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
			printf("\nFailed to open process token\n");
			return (1);
		}

		// Get elevation info
		if (!GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &dwSize)) {
			CloseHandle(hToken);
			printf("\nFailed to get token information\n");
			return (1);
		}

		CloseHandle(hToken);

		// Check if elevated
		if (!elevation.TokenIsElevated) {
			printf("\nAdministrator privileges are required\n");
			return (1);
		}

		// Process actions
		return (control(argc, argv));
	}

#pragma endregion
