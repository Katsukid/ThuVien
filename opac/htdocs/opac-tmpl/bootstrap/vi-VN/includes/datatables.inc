[% USE raw %]
[% USE Asset %]
[% Asset.js("lib/jquery/plugins/jquery.dataTables.min.js") | $raw %]
[% Asset.js("lib/jquery/plugins/dataTables.responsive.min.js") | $raw %]
<script>
    var MSG_DT_FIRST = _("Lần 1");
    var MSG_DT_LAST = _("Trước");
    var MSG_DT_NEXT = _("Tiếp tục");
    var MSG_DT_PREVIOUS = _("Sau");
    var MSG_DT_EMPTY_TABLE = _("Không có dữ liệu hiển thị trong bảng");
    var MSG_DT_INFO = _("Hiển thị từ _START_ tới _END_ trong _TOTAL_");
    var MSG_DT_INFO_EMPTY = _("Không có dữ liệu hiển thị");
    var MSG_DT_INFO_FILTERED = _("(Lọc từ _MAX_)");
    var MSG_DT_LENGTH_MENU = _("Hiển thị trang _MENU_");
    var MSG_DT_LOADING_RECORDS = _("Đang tải...");
    var MSG_DT_PROCESSING = _("Đang xử lý...");
    var MSG_DT_SEARCH = _("Tìm kiếm:");
    var MSG_DT_ZERO_RECORDS = _("Không tìm thấy biểu ghi phù hợp");
    var MSG_DT_COPY_TO_CLIPBOARD = _("Copy to clipboard");
    var MSG_DT_COPY_KEYS = _("Press <i>ctrl</i> or <i>⌘</i> + <i>C</i> to copy the table data<br>to your system clipboard.<br><br>To cancel, click this message or press escape.");
    var MSG_DT_COPIED_ROWS = _("Copied %d rows to clipboard");
    var MSG_DT_COPIED_ONE_ROW = _("Copied one row to clipboard");
    var MSG_CLEAR_FILTER = _("Clear filter");
    var MSG_DT_ALL = _("Tất cả");
    var CONFIG_EXCLUDE_ARTICLES_FROM_SORT = _("a an the");
</script>
[% Asset.js("js/datatables.js") | $raw %]
