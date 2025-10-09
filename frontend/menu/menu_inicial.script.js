// Função para mostrar um menu e esconder os outros
function mostrarMenu(id) {
    const menus = document.querySelectorAll('.menu');
    menus.forEach(menu => {
        if (menu.id === id) {
            menu.classList.remove('hidden');
        } else {
            menu.classList.add('hidden');
        }
    });
}

// Botões do Menu Inicial
document.getElementById('btn-novo-album').addEventListener('click', () => {
    mostrarMenu('menu-album');
});

document.getElementById('btn-acessar-album').addEventListener('click', () => {
    mostrarMenu('menu-album');
});

// Botões do Menu do Álbum
document.getElementById('btn-gerenciar-colecao').addEventListener('click', () => {
    mostrarMenu('menu-gerenciar-album');
});

document.getElementById('btn-voltar-inicial-1').addEventListener('click', () => {
    mostrarMenu('menu-inicial');
});

// Botão do Menu Gerenciar Álbum
document.getElementById('btn-voltar-album').addEventListener('click', () => {
    mostrarMenu('menu-album');
});
