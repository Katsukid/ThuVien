[% USE raw %]
<!-- str/cataloging_additem.inc -->
<script>
    var searchid = '[% searchid | html %]';
    var biblionumber = '[% biblionumber | html %]';
    var frameworkcode = '[% frameworkcode | html %]';
    [% IF popup %]
      var popup = true;
    [% ELSE %]
      var popup = false;
    [% END %]
    var op = '[% op | html %]';
    var LABEL_EDIT_ITEM = _("Edit item");
    var LABEL_DELETE_ITEM = _("Delete item");
    var MSG_FORM_NOT_SUBMITTED = _("Phát hiện các lỗi sau đây, bạn vui lòng kiểm tra và chỉnh sửa lại:");
    var MSG_MANDATORY_FIELDS_EMPTY = _("%s Các trường bắt buộc chưa khai báo thông tin (được đánh dấu)");
    var MSG_IMPORTANT_FIELDS_EMPTY = _("%s important fields empty (highlighted)");
    var MSG_ADD_MULTIPLE_ITEMS = _("You are about to add %s items. Continue?");
    var MSG_ENTER_NUM_ITEMS = _("Vui lòng nhập số bản tài liệu được tạo mới.");
    var MSG_CONFIRM_DELETE_ITEM = _("Bạn chắc chắn muốn xóa bản tài liệu này?");
    var MSG_CONFIRM_ADD_ITEM = _("Are you sure you want to add a new item? Any changes made on this page will be lost.");
    var MSG_CONFIRM_SAVE = _("Are you sure you want to save?");
    var table_settings = [% TablesSettings.GetTableSettings( 'cataloguing', 'additem', 'itemst', 'json' ) | $raw %];
</script>
<!-- / str/cataloging_additem.inc -->
